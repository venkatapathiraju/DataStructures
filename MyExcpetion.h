#pragma once
#include <excpetion>
#include <string>


class RunTimeException 
{
	using namespace std
private:
	string errorMsg;
public:
	RunTimeException(const string& err) : errorMsg(err);
	string getMessage() const { return errMsg; }
};