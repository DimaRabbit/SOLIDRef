#include<iostream>
#include<fstream>
#include<memory>
#include<stdexcept>

using namespace std;

class Formatter 
{
public:
	virtual ~Formatter() = default;
	virtual string format(const string& data)const = 0;
};

class HTMLFormatter : public Formatter 
{
public:
	string format(const string& data)const override
	{
		return "<html>" + data + "<html/>";
	
	}
};

class TextFormatter : public Formatter
{
public:
	string format(const string& data)const override
	{
		return data;

	}
};

class JSONFormatter : public Formatter
{
public:
	string format(const string& data)const override
	{
		return "{ \"data\": \"" + data + "\" }";

	}
};

class Data 
{
private:
	string data;
public:
	explicit Data(string _data) : data(move(_data)) {}

	const string& getData()const 
	{
		return data;
	}
};

void saveTo(ofstream& file, const Data& data, const Formatter& formatter) 
{
	file << formatter.format(data.getData());

}

void saveToAsHTML(ofstream& file, Data& data) 
{
	HTMLFormatter formatter;
	saveTo(file, data, formatter);
}

void saveToAsText(ofstream& file, Data& data) 
{
	TextFormatter formatter;
	saveTo(file, data, formatter);

}
void saveToAsJSON(ofstream& file, Data& data)
{
	JSONFormatter formatter;
	saveTo(file, data, formatter);

}