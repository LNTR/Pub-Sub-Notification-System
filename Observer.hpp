
class Subject;
class Observer
{
public:
    virtual void update(Subject *changed_subject) = 0;
    virtual ~Observer();

protected:
    Observer(){};
};
