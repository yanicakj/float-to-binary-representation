///////////////////////////////////////////////////////////////////
// Name			: Jacob Yanicak
// Date 		: March 10, 2017
// School		: Essex County College
// Description	: This program takes a floating point number and
//				  converts it to its IEEE binary version

#include <iostream>
#include <string>

using namespace std;

// prototypes
void menu();
void ieeefloat();
void ieeedouble();
int checksign(double x);
void floatcollector(double &x);
void doublecollector(double &x);
int splitwhole(double x);
double splitdecimal(double x, int whole);
string wholetobinary(int wholeabs);
string decimaltobinary(double decimalabs);
string concatstrings(string binarywhole, string binarydecimal);
string normalization(string concat1);
string getmantissa(string normalized);
string getfloatmantissa(string normalized);
string getexponent(string concat1, string normalized);
string getfloatexponent(string concat1, string normalized);
string displayresult(double x, int signresult, string exponent, string mantissa, string typebit);
string binarytohex(string finalanswer);

//////////////////////////////////////////////////////////////////////////// main
int main() {

	bool decision = false;

	while (decision == false) {
		int num;
		menu();
		cout << "\n\n\t\tAre you done using this program?" << endl;
		cout << "\t\t1. Yes " << endl;
		cout << "\t\t2. No " << endl;
		cin >> num;
		if (num == 1)
			decision = true;
		else
			decision = false;
	}
	cout << "Peace out dude" << endl;
	return 0;
}
/////////////////////////////////////////////////////////////////////////////

// menu function
void menu()
{
	int choice = 0;
	cout << "\n\t\tThis program takes a decimal number and displays how it would appear in binary form." << endl;
	cout << "\n\t\tWould you like to convert a float or a double? Choose one : " << endl;
	cout << "\n\t\t1. Float (32 bit)" << endl;
	cout << "\t\t2. Double (64 bit)" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		ieeefloat();
		break;
	case 2:
		ieeedouble();
		break;
	default:
		cout << "\n\t\tFollow instructions! Dude!" << endl;
	}
}

// ieeefloat function
void ieeefloat()
{
	double x, decimal, decimalabs;
	int signresult, whole, wholeabs;
	string binarywhole = "";
	string binarydecimal = "";
	string concat1 = "";
	string normalized = "";
	string mantissa = "";
	string exponent = "";
	string finalanswer = "";
	string typebit = "32 bit";
	string hexanswer = "";

	floatcollector(x);
	signresult = checksign(x);
	//cout << "check: sign = " << signresult << endl;
	whole = splitwhole(x);
	decimal = splitdecimal(x, whole);
	//cout << "check: split whole = " << whole << endl;
	//cout << "check: split decimal= " << decimal << endl;
	if (whole >= 0)
		wholeabs = whole;
	else
		wholeabs = -whole;
	if (decimal >= 0)
		decimalabs = decimal;
	else
		decimalabs = -decimal;
	//cout << "check: abs whole = " << wholeabs << endl;
	//cout << "check: abs decimal = " << decimalabs << endl;
	binarywhole = wholetobinary(wholeabs);
	//cout << "check: binary whole = " << binarywhole << endl;
	//cout << "check: string length = " << binarywhole.length() << endl;
	binarydecimal = decimaltobinary(decimalabs);
	//cout << "check: binary decimal = " << binarydecimal << endl;
	//cout << "check: string length = " << binarydecimal.length() << endl;
	concat1 = concatstrings(binarywhole, binarydecimal);
	//cout << "check: concatted string = " << concat1 << endl;
	normalized = normalization(concat1);
	//cout << "check: normalized string = " << normalized << endl;
	mantissa = getfloatmantissa(normalized);
	//cout << "check: mantissa = " << mantissa << endl;
	exponent = getfloatexponent(concat1, normalized);
	//cout << "check: exponent = " << exponent << endl;
	finalanswer = displayresult(x, signresult, exponent, mantissa, typebit);

	hexanswer = binarytohex(finalanswer);

}

// ieeedouble function
void ieeedouble()
{
	double x, decimal, decimalabs;
	int signresult, whole, wholeabs;
	string binarywhole = "";
	string binarydecimal = "";
	string concat1 = "";
	string normalized = "";
	string mantissa = "";
	string exponent = "";
	string finalanswer = "";
	string typebit = "64 bit";
	string hexanswer = "";

	doublecollector(x);
	signresult = checksign(x);
	//cout << "check: sign = " << signresult << endl;
	whole = splitwhole(x);
	decimal = splitdecimal(x, whole);
	//cout << "check: split whole = " << whole << endl;
	//cout << "check: split decimal= " << decimal << endl;
	if (whole >= 0)
		wholeabs = whole;
	else
		wholeabs = -whole;
	if (decimal >= 0)
		decimalabs = decimal;
	else
		decimalabs = -decimal;
	//cout << "check: abs whole = " << wholeabs << endl;
	//cout << "check: abs decimal = " << decimalabs << endl;
	binarywhole = wholetobinary(wholeabs);
	//cout << "check: binary whole = " << binarywhole << endl;
	//cout << "check: string length = " << binarywhole.length() << endl;
	binarydecimal = decimaltobinary(decimalabs);
	//cout << "check: binary decimal = " << binarydecimal << endl;
	//cout << "check: string length = " << binarydecimal.length() << endl;
	concat1 = concatstrings(binarywhole, binarydecimal);
	//cout << "check: concatted string = " << concat1 << endl;
	normalized = normalization(concat1);
	//cout << "check: normalized string = " << normalized << endl;
	mantissa = getmantissa(normalized);
	//cout << "check: mantissa = " << mantissa << endl;
	exponent = getexponent(concat1, normalized);
	//cout << "check: exponent = " << exponent << endl;
	finalanswer = displayresult(x, signresult, exponent, mantissa, typebit);

	hexanswer = binarytohex(finalanswer);
	//cout << hexanswer << endl;
}

// doublecollector function
void doublecollector(double &x)
{
	cout << "\n\t\tPlease enter a double precision number : ";
	cin >> x;

}

// floatcollector function
void floatcollector(double &x)
{
	cout << "\n\t\tPlease enter a floating point number : ";
	cin >> x;

}
// checksign function
int checksign(double x)
{
	int signresult;
	if (x >= 0)
		signresult = 0;
	else
		signresult = 1;
	return signresult;
}

// splitwhole function
int splitwhole(double x)
{
	int whole;
	whole = (int)x;
	return whole;
}

// splitdecimal function
double splitdecimal(double x, int whole)
{
	double decimal;
	decimal = x - whole;
	return decimal;
}

// wholetobinary function
string wholetobinary(int wholeabs)
{
	string binarywhole = "";
	string binchar = "";
	int bin, stringlength;

	int i = wholeabs;
	while (i > 0) {
		bin = i % 2;
		binchar = to_string(bin);
		binarywhole = binchar + binarywhole;
		i = i / 2;
	}
	stringlength = binarywhole.length();
	while (stringlength < 8){
		binarywhole = "0" + binarywhole;
		stringlength++;
	}

	return binarywhole;
}

// decimaltobinary function
string decimaltobinary(double decimalabs)
{
	string binarydecimal = ".";
	double twotimes = 0.0;
	double remainder = 0.0;
	remainder = decimalabs;

	for (int i = 0; i < 100; i++) { // using 100 for double conversion
		twotimes = remainder * 2;
		if (twotimes >= 1) {
			binarydecimal = binarydecimal + "1";
			remainder = twotimes - 1;
		}
		else {
			binarydecimal = binarydecimal + "0";
			remainder = twotimes;
		}
	}
	return binarydecimal;
}

// concatstrings function
string concatstrings(string binarywhole, string binarydecimal)
{
	string concat1 = "";
	concat1 = binarywhole + binarydecimal;
	return concat1;
}

// normalization function
string normalization(string concat1)
{
	string normalized = "";
	string copy = "";
	string pos = "";
	string sub1 = "";
	string sub2 = "";
	int j = 0;

	for (int i = 0; i < concat1.length(); i++){
		pos = concat1[i];
		if (pos == "."){
			copy = concat1.erase(i, 1);
			break;
		}
	}
	//cout << "check: string with no decimal: " << copy << endl;
	for (int i = 0; i < concat1.length(); i++){
		pos = concat1[i];
		if (pos == "1"){
			j = i + 1;
			sub1 = concat1.substr(0, j);
			sub2 = copy.substr(j, copy.length());
			normalized = sub1 + "." + sub2;
			break;
		}
	}
	//cout << "check: sub1 = " << sub1 << endl;
	//cout << "check: sub2 = " << sub2 << endl;
	return normalized;
}

// getmantissa function
string getmantissa(string normalized)
{
	string mantissa = "";
	string pos = "";
	int j = 0;

	for (int i = 0; i < normalized.length(); i++){
		pos = normalized[i];
		j = i + 1;
		if (pos == "."){
			mantissa = normalized.substr(j, 52);
			break;
		}
	}
	return mantissa;
}

// getfloatmantissa function
string getfloatmantissa(string normalized)
{
	string mantissa = "";
	string pos = "";
	int j = 0;

	for (int i = 0; i < normalized.length(); i++){
		pos = normalized[i];
		j = i + 1;
		if (pos == "."){
			mantissa = normalized.substr(j, 23);
			break;
		}
	}
	return mantissa;
}

// getexponent function
string getexponent(string concat1, string normalized)
{
	string exponent = ""; // needs to be 11 digits long
	string pos = "";
	int place1 = 0;
	int place2 = 0;
	int change = 0;
	int constant = 1023;
	string binchar = "";
	int bin, stringlength;
	int j = 0;

	for (int i = 0; i < concat1.length(); i++){
		pos = concat1[i];
		if (pos == "."){
			place1 = i;
			break;
		}
	}
	for (int i = 0; i < normalized.length(); i++){
		pos = normalized[i];
		if (pos == "."){
			place2 = i;
			break;
		}
	}
	//cout << "check: place1 = " << place1 << endl;
	//cout << "check: place2 = " << place2 << endl;

	change = place1 - place2;
	constant = constant + change;
	//cout << "check: constant = " << constant << endl;

	j = constant;
	while (j > 0) {
		bin = j % 2;
		binchar = to_string(bin);
		exponent = binchar + exponent;
		j = j / 2;
	}
	stringlength = exponent.length();
	while (stringlength < 11){
		exponent = "0" + exponent;
		stringlength++;
	}

	return exponent;
}

// getfloatexponent function
string getfloatexponent(string concat1, string normalized)
{
	string exponent = ""; // needs to be 8 digits long
	string pos = "";
	int place1 = 0;
	int place2 = 0;
	int change = 0;
	int constant = 127;
	string binchar = "";
	int bin, stringlength;
	int j = 0;

	for (int i = 0; i < concat1.length(); i++){
		pos = concat1[i];
		if (pos == "."){
			place1 = i;
			break;
		}
	}
	for (int i = 0; i < normalized.length(); i++){
		pos = normalized[i];
		if (pos == "."){
			place2 = i;
			break;
		}
	}
	//cout << "check: place1 = " << place1 << endl;
	//cout << "check: place2 = " << place2 << endl;

	change = place1 - place2;
	constant = constant + change;
	//cout << "check: constant = " << constant << endl;

	j = constant;
	while (j > 0) {
		bin = j % 2;
		binchar = to_string(bin);
		exponent = binchar + exponent;
		j = j / 2;
	}
	stringlength = exponent.length();
	while (stringlength < 8){
		exponent = "0" + exponent;
		stringlength++;
	}

	return exponent;
}

// displayresult function
string displayresult(double x, int signresult, string exponent, string mantissa, string typebit)
{
	string finalanswer = "";
	string signstring = "";

	signstring = to_string(signresult);
	finalanswer = signstring + exponent + mantissa;
	// Enter clear screen command here for respective OS
	cout << "\n\t\tThe " << typebit << " binary version of the decimal " << x << " you have entered earlier is : " << endl;
	cout << "\n\t\t" << signstring + exponent + mantissa << endl;
	cout << "\n\t\tsign : \t\t" << signstring << endl;
	cout << "\t\texponent : \t" << exponent << endl;
	cout << "\t\tmantissa : \t" << mantissa << endl;

	return finalanswer;
}

// converting a binary to hex
string binarytohex(string finalanswer)
{
	string hexanswer = "";
	string subsection = "";
	int subint = 0;
	//cout << "check : in the function" << endl;
	if (finalanswer.length() == 32) { // 8 sub strings
		for (int i = 0; i <= 28; i = i + 4){
			subsection = finalanswer.substr(i, 4);
			//cout << "check : substring of whole" << endl;
			if (subsection == "0000")
				hexanswer = hexanswer + "0";
			else if (subsection == "0001")
				hexanswer = hexanswer + "1";
			else if (subsection == "0010")
				hexanswer = hexanswer + "2";
			else if (subsection == "0011")
				hexanswer = hexanswer + "3";
			else if (subsection == "0100")
				hexanswer = hexanswer + "4";
			else if (subsection == "0101")
				hexanswer = hexanswer + "5";
			else if (subsection == "0110")
				hexanswer = hexanswer + "6";
			else if (subsection == "0111")
				hexanswer = hexanswer + "7";
			else if (subsection == "1000")
				hexanswer = hexanswer + "8";
			else if (subsection == "1001")
				hexanswer = hexanswer + "9";
			else if (subsection == "1010")
				hexanswer = hexanswer + "a";
			else if (subsection == "1011")
				hexanswer = hexanswer + "b";
			else if (subsection == "1100")
				hexanswer = hexanswer + "c";
			else if (subsection == "1101")
				hexanswer = hexanswer + "d";
			else if (subsection == "1110")
				hexanswer = hexanswer + "e";
			else if (subsection == "1111")
				hexanswer = hexanswer + "f";
			else
				cout << "oops" << endl;
		}
	}
	else if (finalanswer.length() == 64) {
		for (int i = 0; i <= 60; i = i + 4){
			subsection = finalanswer.substr(i, 4);
			if (subsection == "0000")
				hexanswer = hexanswer + "0";
			else if (subsection == "0001")
				hexanswer = hexanswer + "1";
			else if (subsection == "0010")
				hexanswer = hexanswer + "2";
			else if (subsection == "0011")
				hexanswer = hexanswer + "3";
			else if (subsection == "0100")
				hexanswer = hexanswer + "4";
			else if (subsection == "0101")
				hexanswer = hexanswer + "5";
			else if (subsection == "0110")
				hexanswer = hexanswer + "6";
			else if (subsection == "0111")
				hexanswer = hexanswer + "7";
			else if (subsection == "1000")
				hexanswer = hexanswer + "8";
			else if (subsection == "1001")
				hexanswer = hexanswer + "9";
			else if (subsection == "1010")
				hexanswer = hexanswer + "a";
			else if (subsection == "1011")
				hexanswer = hexanswer + "b";
			else if (subsection == "1100")
				hexanswer = hexanswer + "c";
			else if (subsection == "1101")
				hexanswer = hexanswer + "d";
			else if (subsection == "1110")
				hexanswer = hexanswer + "e";
			else if (subsection == "1111")
				hexanswer = hexanswer + "f";
			else
				cout << "oops" << endl;
		}

	}
	else
		cout << "oops" << endl;
	cout << "\n\t\tHexidecimal form : " << hexanswer << endl;

	return hexanswer;
}
