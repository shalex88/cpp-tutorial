#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include <memory>

class HtmlBuilder;

class HtmlElement {
public:
	std::string name;
	std::string text;
	std::vector<HtmlElement> elements;
	const size_t indent_size = 2;

	HtmlElement() = default;

	HtmlElement(std::string name, std::string text)
			: name(std::move(name)),
			  text(std::move(text)) {
	}

	[[nodiscard]] std::string str(int indent = 0) const {
		std::ostringstream oss;
		std::string i(indent_size * indent, ' ');
		oss << i << "<" << name << ">" << std::endl;
		if (!text.empty())
			oss << std::string(indent_size * (indent + 1), ' ') << text << std::endl;

		for (const auto& e: elements)
			oss << e.str(indent + 1);

		oss << i << "</" << name << ">" << std::endl;

		return oss.str();
	}

	static std::unique_ptr<HtmlBuilder> build(const std::string& root_name) {
		return make_unique<HtmlBuilder>(root_name);
	}
};

class HtmlBuilder {
public:
	explicit HtmlBuilder(std::string root_name) {
		root.name = std::move(root_name);
	}

	// void to start with
	HtmlBuilder& add_child(const std::string& child_name, const std::string& child_text) {
		HtmlElement e{ child_name, child_text };
		root.elements.emplace_back(e);
		return *this;
	}

	// pointer based
	HtmlBuilder* add_child_2(const std::string& child_name, const std::string& child_text) {
		HtmlElement e{ child_name, child_text };
		root.elements.emplace_back(e);
		return this;
	}

	[[nodiscard]] std::string str() const {
		return root.str();
	}

	explicit operator HtmlElement() const {
		return root;
	}

	HtmlElement root;
};

int main() {
	// Without Builder 1
	auto text = "hello";
	std::string output;
	output += "<p>";
	output += text;
	output += "</p>";
	std::cout << "<p>" << text << "</p>" << std::endl;

	// Without Builder 2
	std::string words[] = { "hello", "world" };
	std::ostringstream oss;
	oss << "<ul>" << std::endl;
	for (const auto& w: words)
		oss << "  <li>" << w << "</li>" << std::endl;
	oss << "</ul>" << std::endl;
	std::cout << oss.str().c_str();

	// With Fluent Builder 1
	HtmlBuilder builder{ "ul" };
	builder.add_child("li", "hello").add_child("li", "world");
	std::cout << builder.str() << std::endl;

	// With Fluent Builder 2
//	auto builder2 = HtmlElement::build("ul")->add_child_2("li", "hello")
//			->add_child_2("li", "world");
//	std::cout << builder2->str() << std::endl;

	return 0;
}