// In this code i will write the good desgin of the Document Editor
// In this i will write code in such a manner so that it will follow all five solid principle of the LLD
// SOLID Principles

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Document Element class
// This will be abstract class and the Element of the Document will inherit it
class DocumentElement
{
public:
    virtual string render() = 0;
    virtual ~DocumentElement() = default;
};

// Text Element : which contains text of the Doucment
class TextElement : public DocumentElement
{
private:
    string text;

public:
    // constructer
    TextElement(string text)
    {
        this->text = text;
    }

    string render() override
    {
        return this->text;
    }
};

// Image Element : Which contains path of that Image
class ImageElement : public DocumentElement
{
private:
    string ImagePath;

public:
    // Constructer
    ImageElement(string Path)
    {
        this->ImagePath = Path;
    }

    string render() override
    {
        return this->ImagePath;
    }
};

// NextLine Element : This is responsible for the new line
class NextLineElement : public DocumentElement
{
public:
    string render() override
    {
        return "\n";
    }
};

// TabSpace Element : This is resposible for the tab space
class TabSpaceElement : public DocumentElement
{
public:
    string render() override
    {
        return "\t";
    }
};

// This class helps to add new element to the document and also help to render it
class Document
{
private:
    vector<DocumentElement *> docs;

public:
    // Add new element in the document
    void addElement(DocumentElement *el)
    {
        docs.push_back(el);
    }

    // render the whole document
    string render()
    {
        string result;
        for (auto el : this->docs)
        {
            result += el->render();
        }
        return result;
    }

    virtual ~Document() = default;
};

// This class help to save the document in to different different resource
class Persistance
{
public:
    virtual void save(string doc) = 0;
    virtual ~Persistance() = default;
};

// Save to File : helps to save the render document into the file
class SaveToFile : public Persistance
{
public:
    void save(string doc) override
    {
        ofstream file("good_design_document.txt");
        if (file.is_open())
        {
            file << doc;
            file.close();
            cout << "Your doc is save to file : good_design_document.text..." << endl;
        }
        else
        {
            cout << "Error : cannot write inside the file....." << endl;
        }
    }
};

// Save To DB : helps to save the render document into the Data Base
class SaveToDB : public Persistance
{
public:
    void save(string text) override
    {
        cout << "Your Document is save to DataBase successfully...." << endl;
    }
};

// Now we will write class of Document Editor which will work as a interface between the user and our system
class DocumentEditor
{
private:
    Persistance *db;
    Document *doc;
    string renderDoc;

public:
    // Constructer
    DocumentEditor(Persistance *db, Document *doc)
    {
        this->doc = doc;
        this->db = db;
    }

    // helps to add New Text into document
    void addText(string text)
    {
        this->doc->addElement(new TextElement(text));
    }

    // helps to add New Image into Document
    void addImage(string imagePath)
    {
        this->doc->addElement(new ImageElement(imagePath));
    }

    // helps to add new Line into Document
    void addNewLine()
    {
        this->doc->addElement(new NextLineElement);
    }

    // helps to add Tab space into document
    void addTabSpace()
    {
        this->doc->addElement(new TabSpaceElement);
    }

    // This helps to render the document
    string render()
    {
        this->renderDoc = doc->render();
        return this->renderDoc;
    }

    // This helps to Save our Document
    void save()
    {
        db->save(this->renderDoc);
    }
};

int main()
{
    SaveToFile *db = new SaveToFile;
    Document *docs = new Document;
    DocumentEditor doc(db, docs);
    doc.addText("Hello, My name is Brij Patel");
    doc.addNewLine();
    doc.addImage("Image.jpg");
    doc.addNewLine();
    doc.addTabSpace();
    doc.addText("And I Loves Radha Rani so much.....");
    cout << doc.render() << endl;
    doc.save();

    return 0;
}