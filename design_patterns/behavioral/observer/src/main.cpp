#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <mutex>

class IObserver {
 public:
  virtual ~IObserver() = default;
  virtual void Update(const std::string &message_from_subject) = 0;
};

class IEventManager {
 public:
  virtual ~IEventManager() = default;
  virtual void Subscribe(IObserver *observer) = 0;
  virtual void Unsubscribe(IObserver *observer) = 0;
  virtual void Notify(std::string message) = 0;
};

class EventManager : public IEventManager {
 public:
  ~EventManager() override = default;

  /* Subscription management methods */
  void Subscribe(IObserver *observer) override {
    std::scoped_lock<std::mutex> lock{mtx};
    observers_.push_back(observer);
  }
  void Unsubscribe(IObserver *observer) override {
    std::scoped_lock<std::mutex> lock{mtx};
    observers_.remove(observer);
  }
  void Notify(std::string message) override {
    std::scoped_lock<std::mutex> lock{mtx};
    auto iterator = observers_.begin();
    HowManyObserver();
    while (iterator != observers_.end()) {
      (*iterator)->Update(message);
      ++iterator;
    }
  }

  void HowManyObserver() {
    std::cout << "There are " << observers_.size() << " observers in the list.\n";
  }

 private:
  std::list<IObserver *> observers_;
  std::mutex mtx;
};

class Subject {
 public:
  Subject() = default;
  ~Subject() = default;
  EventManager event_manager_;
  void CreateMessage(std::string message = "Empty") {
    message_ = std::move(message);
    event_manager_.Notify(message_);
  }
 private:
  std::string message_;
};

class AObserver : public IObserver {
 public:
  explicit AObserver(EventManager &subject) : event_manager_(subject) {
    this->event_manager_.Subscribe(this);
  }
  ~AObserver() override = default;

  void Update(const std::string &message_from_subject) override {
    message_from_subject_ = message_from_subject;
    ObserverLogic();
  }

  void RemoveMeFromTheList() {
    event_manager_.Unsubscribe(this);
    std::cout << "Observer removed from the list\n";
  }

  virtual void ObserverLogic() = 0;

 protected:
  std::string message_from_subject_;
  EventManager &event_manager_;
};

class ConcreteObserverA : public AObserver {
 public:
  explicit ConcreteObserverA(EventManager &subject) : AObserver(subject) {
    std::cout << "Hi, I'm the ObserverA\n";
  }
  ~ConcreteObserverA() override = default;

  void ObserverLogic() override {
    std::cout << "ObserverA: a new message is available --> " << this->message_from_subject_<< std::endl;
  }
};

class ConcreteObserverB : public AObserver {
 public:
  explicit ConcreteObserverB(EventManager &subject) : AObserver(subject) {
    std::cout << "Hi, I'm the ObserverA\n";
  }
  ~ConcreteObserverB() override = default;

  void ObserverLogic() override {
    std::cout << "ObserverA: a new message is available --> " << this->message_from_subject_<< std::endl;
  }
};

void ClientCode() {
  auto *p_subject = new Subject;
  auto *p_observer1 = new ConcreteObserverA(p_subject->event_manager_);
  auto *p_observer2 = new ConcreteObserverB(p_subject->event_manager_);

  p_subject->CreateMessage("The weather is hot today! :p");

  p_observer2->RemoveMeFromTheList();

  p_subject->CreateMessage("My new car is great! ;)");

  p_observer1->RemoveMeFromTheList();

  delete p_observer1;
  delete p_observer2;
  delete p_subject;
}

auto main() -> int {
  ClientCode();

  return 0;
}