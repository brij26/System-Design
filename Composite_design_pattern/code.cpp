#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class FileSystemItem
{
public:
    virtual ~FileSystemItem() = default;
    virtual void ls(int indent = 0) = 0;
    virtual void openAll(int indent = 0) = 0;
    virtual int getSize() = 0;
    virtual FileSystemItem *cd(const string &name) = 0;
    virtual string getName() = 0;
    virtual bool isFolder() = 0;
};

// Leaf : File
class File : public FileSystemItem
{
private:
    string name;
    int size;

public:
    File(const string &name, int size)
    {
        this->name = name;
        this->size = size;
    }

    void ls(int indent = 0) override
    {
        cout << string(indent, ' ') << this->name << '\n';
    }

    void openAll(int indent = 0) override
    {
        cout << string(indent, ' ') << this->name << '\n';
    }

    int getSize() override
    {
        return this->size;
    }

    FileSystemItem *cd(const string &name) override
    {
        return nullptr;
    }

    string getName() override
    {
        return this->name;
    }

    bool isFolder() override
    {
        return false;
    }
};

class Folder : public FileSystemItem
{
private:
    string name;
    vector<FileSystemItem *> childern;

public:
    Folder(const string &name)
    {
        this->name = name;
    }

    ~Folder()
    {
        for (auto c : childern)
        {
            delete c;
        }
    }

    void add(FileSystemItem *item)
    {
        this->childern.push_back(item);
    }

    void ls(int indent = 0) override
    {
        for (auto c : this->childern)
        {
            if (c->isFolder())
            {
                cout << string(indent, ' ') << "(+)" << c->getName() << '\n';
            }
            else
            {
                cout << string(indent, ' ') << c->getName() << '\n';
            }
        }
    }

    void openAll(int indent = 0) override
    {
        cout << string(indent, ' ') << "(+)" << name << '\n';
        for (auto c : this->childern)
        {
            c->openAll(indent + 4);
        }
    }

    int getSize() override
    {
        int total = 0;
        for (auto c : childern)
        {
            total += c->getSize();
        }
        return total;
    }

    FileSystemItem *cd(const string &name) override
    {
        for (auto c : childern)
        {
            if (c->isFolder() && c->getName() == name)
            {
                return c;
            }
        }
        return nullptr;
    }

    string getName() override
    {
        return this->name;
    }

    bool isFolder() override
    {
        return true;
    }
};

int main()
{
    // Build file system
    Folder *root = new Folder("root");
    root->add(new File("file1.txt", 1));
    root->add(new File("file2.txt", 1));

    Folder *docs = new Folder("docs");
    docs->add(new File("resume.pdf", 1));
    docs->add(new File("notes.txt", 1));
    root->add(docs);

    Folder *images = new Folder("images");
    images->add(new File("photo.jpg", 1));
    root->add(images);

    root->ls();

    docs->ls();

    root->openAll();

    FileSystemItem *cwd = root->cd("docs");
    if (cwd != nullptr)
    {
        cwd->ls();
    }
    else
    {
        cout << "\n Could not cd into docs \n";
    }

    cout << root->getSize();

    // Cleanup
    delete root;
    return 0;
}