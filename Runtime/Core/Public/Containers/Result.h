#pragma once
#ifndef RESULT_H
#define RESULT_H


/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></template paramter T must have non-paramters construct function>
template<typename T>
class TResult
{
	using type = T;
	using self_type = TResult<T>;
public:
	type value;
	bool result;
private:
};

#endif // !RESULT_H
