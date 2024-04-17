class Stroika {
private:
    string name;
    int price;
    string whomade;
    string color;

public:
    Stroika();
    Stroika(const string& name, int price, const string& whomade, const string& color);
    friend ostream& operator<<(ostream& os, const Stroika& stroika);
    friend istream& operator>>(istream& is, Stroika& stroika);
    void edit(const string& newName, int newPrice, const string& newWhomade, const string& newColor);
    string getName()const;
    int getPrice()const;
    string getWhomade()const;
    string getColor()const;
};

void saveData(const Stroika* stroiki, int size);
void readData(Stroika* stroiki, int size);
void addElement(Stroika*& stroiki, int& size, const Stroika& newElement);
void deleteElement(Stroika*& stroiki, int& size, const string& name);
void editElement(Stroika* stroiki, int size, const string& name, const string& newName, int newPrice, const string& newWhomade, const string& newColor);
void searchElement(const Stroika* stroiki, int size, const string& name);
void printArray(const Stroika* stroiki, int size);
