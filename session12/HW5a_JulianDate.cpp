//Xin Song -- Juliandate
//the math method is from http://www.math.harvard.edu/~knill/3dprinter/exhibits/bc/Meeus1988.pdf (our professor mentioned)
#include<vector>
#include<iostream>
#include<time.h>
using namespace std;

static double J2000 = 2451545;

bool leapYear(int year) {
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ) {
		return true;
	}
	else {
		return false;
	}
}
// get local time function 
vector<int> getTimeStamp() {
	time_t rawtime;
	struct tm * timeinfo;
	time( &rawtime );
	timeinfo = localtime( &rawtime );
	char year[5], mon[3], mday[3], hour[3], minute[3], sec[3];
	sprintf(year, "%d", timeinfo->tm_year + 1900);
	sprintf(mon, "%d", timeinfo->tm_mon + 1);
	sprintf(mday, "%d", timeinfo->tm_mday);
	sprintf(hour, "%d", timeinfo->tm_hour);
	sprintf(minute, "%d", timeinfo->tm_min);
	sprintf(sec, "%d", timeinfo->tm_sec);

	vector<int> todaydate;
	todaydate.push_back(stoi(string(year)));
	todaydate.push_back(stoi(string(mon)));
	todaydate.push_back(stoi(string(mday)));
	todaydate.push_back(stoi(string(hour)));
	todaydate.push_back(stoi(string(minute)));
	todaydate.push_back(stoi(string(sec)));
	return todaydate;
}
//process month
string transMonth(int M){
	switch(M){
		case 1 : return "Jan"; break;
		case 2 : return "Feb"; break;
		case 3 : return "Mar"; break;
		case 4 : return "Apr"; break;
		case 5 : return "May"; break;
		case 6 : return "Jun"; break;
		case 7 : return "Jul"; break;
		case 8 : return "Aug"; break;
		case 9 : return "Sep"; break;
		case 10 : return "Oct"; break;
		case 11 : return "Nov"; break;
		default:  // the only default value is december
		   return "Dec";
		   break;
	}
}


//convert JulianDate to Calendar Date
//I put this convertJD() method out the class, because when you input a number, 
//this convertJD() method still should work, for example convertJD(14).
string convertJD(double jd){
	//get date : hour, minute, second
	double hms = jd - (int)jd;
	int h = int(hms * 24);
	int m = int((hms * 24 - h) * 60);
	int s = int(((hms*24-h) * 60 - m) * 60);
	//get date : year month days
	int Z = int((int)jd + 0.5 + J2000);
	int A;
	double alf;
	if (Z < 2299161){
		A = Z;
	}
	else{
		alf = int((Z - 1867216.25)/36524.25);
		A = Z + 1 + alf - int(alf/4);
	}
	int B = A + 1524;
	int C = int((B-122.1)/365.25);
	int D = int(365.25 * C);
	int E = int((B - D)/30.6001);
	double dayofM = B - D - int(30.6001*E) + hms;
	int M = 0;
	if (E < 13.5) {
		M = E - 1;
	}
	if ( E > 13.5){
		M = E - 13;
	}
	int year; 
	if (M > 2.5) {
		year = C - 4716;
	}
	if(M < 2.5){
		year = C - 4715;
	}
	string hour,min,second;
	if(h < 10) {
		hour = '0' + to_string(h);
	}
	else{
		hour = to_string(h);
	}
	if(m < 10) {
		min = '0' + to_string(m);
	}
	else{
		min = to_string(m);
	}
	if(s < 10) {
		second = '0'+ to_string(s);
	}
	else{
		second = to_string(s);
	}
	return to_string(year) + " " +  transMonth(M) + " " + to_string((int)dayofM) + " " + hour + ":" + min + ":" + second ;
}

class JulianDate{
private:
	double jd; //each 1 is 1 day
public:
	//constructor --- convert Calendar Date to JulianDate
	JulianDate(int year, int M, int D, int h, int m, int s){
		int N; // N: the number of days in current year, it may not be larger than 365 or 366
		if(leapYear(year)) {
			N = int(275*M/9) - int((M + 9)/12) + D - 30;	
		}
		else {
			N = int(275*M/9) - 2 * int((M + 9)/12) + D - 30;
		}
		jd = N + h/24. + m/24./60. + s/24./60./60. - 1;
		//Calculate the number of days from 2000 to the previous years
		for(int i = year - 1; i >= 2000; i--) {
			if(leapYear(i)){
				jd += 366;
			}
			else{
				jd += 365;
			}
		}
	}
	//constructor -- convert the date right now to JulianDate
	JulianDate(){
		vector<int> t = getTimeStamp();
		jd = JulianDate(t[0],t[1],t[2],t[3],t[4],t[5]).jd;
	}
	//JulianDate + n
	friend double operator+(const JulianDate j, const double n){
		cout << "what is " << n << " days from " << convertJD(j.jd) << "?  It's " << convertJD(j.jd+n) << endl;
		return j.jd + n;
	}
	//JulianDate - n
	friend double operator-(const JulianDate j, const double n){	
		cout << "what is " << n << " days before " << convertJD(j.jd) << "?  It's " << convertJD(j.jd - n) << endl;
		return j.jd - n;
	}
	//Two JulianDate's difference 
	friend double operator-(const JulianDate j1, const JulianDate j2){	
		return j1.jd - j2.jd;
	}
	//operator <<
	friend ostream& operator <<(ostream& s, const JulianDate& j){
		s << j.jd;
		return s;
	}
	//convert JulianDate to Calendar Date
    string convertJDmethod(){
		return convertJD(jd);
	}
};

int main() {
	JulianDate today;
//	cout << "today:" << today.convertJDmethod() << endl;
	JulianDate a(2000, 1, 1, 00, 00, 00); //midnight, january 1, 2000
//	cout << a << endl;
//	cout << a.convertJDmethod() << endl;
	JulianDate b(2000, 2,28, 00,00,00);
//  cout << "(2000, 2,28, 00,00,00): "<< b << endl;
//	cout << b.convertJDmethod() << endl;
	JulianDate c(2000, 3, 5, 04, 30, 00);	
//  cout << "(2000, 3, 5, 04, 30, 00):"<< c << endl;
//	cout << c.convertJDmethod() << endl;
	JulianDate d(2000, 1, 3, 00, 00, 00);	
//  cout <<"(2000, 1, 3, 00, 00, 00):" << d << endl;
//	cout << d.convertJDmethod() << endl;
	JulianDate e(2000, 1, 3, 12, 00, 00);	
//  cout <<"(2000, 1, 3, 12, 00, 00) " << e << endl;
//	cout << e.convertJDmethod() << endl;
	
	cout << d - a << " days\n"; //2.0
	cout << e - a << " days\n"; //2.5
	cout << a + 13 << endl; // what is 13 days from Jan.1 2000? Jan 14, 2000;
	cout << a + 13.5 << endl; //  what is 13 days from Jan.1 2000? Jan 14, 2000;

}
