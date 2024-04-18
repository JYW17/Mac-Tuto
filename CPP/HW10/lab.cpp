#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void input(double &invest, double &rate, double &term);
void process(double invest, double rate, double term, double &multiplier, double &futureValue);
void output(double invest, double rate, double term, double multiplier, double futureValue);

double getInputValue(string message);
double findMultiplier(double rate, double years);
void printData(double invest, double rate, double term);
void printResult(double multiplier, double futureValue);

int main(){

  double invest, rate, term;
  double multiplier, futureValue;
  
  input(invest, rate, term);
  process(invest, rate, term, multiplier, futureValue);
  output(invest, rate, term, multiplier, futureValue);

  return 0;
}

// 주요 함수들
void input(double &invest, double &rate, double &term){
  invest = getInputValue("투자 금액을 입력하세요: ");
  rate = getInputValue("1년마다의 이율을 입력하세요: ");
  term = getInputValue("투자 기간(년)을 입력하세요: ");
}

void process(double invest, double rate, double term, double &multiplier, double &futureValue){
  multiplier = findMultiplier(rate, term);
  futureValue = invest * multiplier;
}

void output(double invest, double rate, double term, double multiplier, double futureValue){
  printData(invest, rate, term);
  printResult(multiplier, futureValue);
}

// 부가 함수들
double getInputValue(string message){
  double input;
  
  do{
    cout << message;
    cin >> input;
  } while(input <= 0);

  return input;
}

double findMultiplier(double rate, double years){
  return pow(1 + rate/100, years);
}

void printData(double invest, double rate, double term){
  cout << endl;
  cout << "투자 정보" << endl;
  cout << "투자 금액: " << invest << endl;
  cout << "이율: " << rate << "%(1년 기준)" << endl;
  cout << "투자 기간: " << term << "년" << endl;
}

void printResult(double multiplier, double futureValue){
  cout << endl;
  cout << "투자의 승수 = " << multiplier << endl;
  cout << "미래 가치: " << futureValue << endl;
}
