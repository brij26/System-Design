// In this we will try to implement the notification service of the youtube whenever a channel uploads a new video and its notify about it to all the subscriber of that channel

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Create one pure abstract class Subscriber
class ISubscriber
{
public:
    virtual void update() = 0;
    virtual ~ISubscriber() = default;
};

// create one pure abstract class channel
class IChannel
{
public:
    virtual void subscribe(ISubscriber *s) = 0;
    virtual void unsubscribe(ISubscriber *s) = 0;
    virtual void notify() = 0;
    virtual ~IChannel() = default;
};

// now we will inhertes the IChannel class and create one channel class
class Channel : public IChannel
{
private:
    vector<ISubscriber *> subscribers; // list of all the subscriber
    string name;
    string latest_video; // title of the latest uploaded video

public:
    Channel(const string &name)
    {
        this->name = name;
    }

    // add subscriber if it is not present in subscribers list
    void subscribe(ISubscriber *sub) override
    {
        if (find(this->subscribers.begin(), this->subscribers.end(), sub) == this->subscribers.end())
        {
            this->subscribers.push_back(sub);
        }
    }

    // remove subcriber from the list if it is present
    void unsubscribe(ISubscriber *sub) override
    {
        auto it = find(this->subscribers.begin(), this->subscribers.end(), sub);
        if (it != this->subscribers.end())
        {
            this->subscribers.erase(it);
        }
    }

    // Notify the subscribers
    void notify() override
    {
        for (auto sub : subscribers)
        {
            sub->update();
        }
    }

    void uploadVideo(const string &title)
    {
        latest_video = title;
        cout << "\n[" << this->name << " Uploaded \"" << title << "\"]" << endl;
        notify();
    }

    string getVideo()
    {
        return "\nCheckout Our New Video : " + latest_video + "\n";
    }
};

class Subscriber : public ISubscriber
{
private:
    string name;
    Channel *channel;

public:
    Subscriber(const string &name, Channel *ch)
    {
        this->name = name;
        this->channel = ch;
    }

    void update() override
    {
        cout << "Hey! " << this->name << "," << this->channel->getVideo();
    }
};

int main()
{
    Channel *channel = new Channel("XYZ");

    Subscriber *sub1 = new Subscriber("Brij", channel);
    Subscriber *sub2 = new Subscriber("Patel", channel);

    channel->subscribe(sub1);
    channel->subscribe(sub2);

    channel->uploadVideo("Video1");

    channel->unsubscribe(sub2);

    channel->uploadVideo("Video2");

    delete sub1;
    delete sub2;
    delete channel;

    return 0;
}
