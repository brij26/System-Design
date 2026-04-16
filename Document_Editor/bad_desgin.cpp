// In bad design we write whole code in one class or one class is doing all the work
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Document Editor class handles all the task
class DocumentEditor
{
private:
    vector<string> el;
    string renderedDocument;

public:
    // we add string text as it is in our vector
    void addText(string text)
    {
        this->el.push_back(text);
    }

    // we add image Path instead of original image in our vector
    void addImage(string imagePath)
    {
        this->el.push_back(imagePath);
    }

    string renderDocument()
    {
        if (renderedDocument.empty())
        {
            string result;
            for (auto element : this->el)
            {
                if (element.size() > 4 && (element.substr(element.size() - 4) == ".jpg" ||
                                           element.substr(element.size() - 4) == ".png"))
                {
                    result += "[Image: " + element + "]" + "\n";
                }
                else
                {
                    result += element + "\n";
                }
            }
            renderedDocument = result;
        }
        return renderedDocument;
    }

    void SaveToFile()
    {
        ofstream file("document.txt");
        if (file.is_open())
        {
            file << this->renderedDocument;
            file.close();
            cout << "Document saved to document.txt" << endl;
        }
        else
        {
            cout << "Error : Unable to open file for writing ..." << endl;
        }
    }
};

int main()
{
    DocumentEditor editor;

    editor.addText("Hello, World!");
    editor.addImage("image.jpg");
    editor.addText("This is a document editor");

    cout << editor.renderDocument() << endl;

    editor.SaveToFile();

    return 0;
}