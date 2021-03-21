#include "practices.h"
#include <iostream>
#include <optional>
#include <variant>
#include <regex>
#include <thread>
#include <mutex>
using namespace std;

namespace practices
{
	void function1_3()
	{
		cout << "Hello, World" << endl;
	}

	void function1_4()
	{
		int v1 = 0, v2 = 0;
		cin >> v1 >> v2;
		cout << "The sum is" << v1 * v2 << endl;
	}

	void function1_9()
	{
		int sum = 0, i = 50;
		while (i <= 100)
		{
			sum += i++;
		} 
	}

	void function1_10()
	{
		int i = 10;
		while (i > 1)
		{
			cout << --i << " ";
		}
		cout << endl;
	}

	void function1_11()
	{
		cout << "Please Enter 2 numbers :" << endl;
		int v1 = 0, v2 = 0;
		cin >> v1 >> v2;

		int min = fmin(v1, v2);
		int max = fmax(v1, v2);

		cout << "Numbers between " << min << " and " << max << " is:" << endl;

		while (min <= max)
		{
			cout << min++ << " ";
		}
		cout << endl;
	} 

	void function1_16()
	{
		cout << "Please enter several numbers :" << endl;

		int i = 0, sum = 0;
		while (cin >> i)
		{
			sum += i;
		}

		cout << "The sum is :" << sum << endl;
	}

	void test0()
	{
		string str = "123>Linjay@gmail.com<123";
		regex e("([[:w:]]+)@([[:w:]]+)\.com");
		smatch m;
		bool found = regex_search(str, m, e);
		if (found)
		{
			cout << m.str() << endl;
		}
		else cout << "Not Found" << endl;
	}

	void test1()
	{
		string str = "123>Linjay@gmail.com<123"
			"123>Linfen@gmail.com<123";
		regex e("([[:w:]]+)@([[:w:]]+)\.com");
		smatch m;
		bool found = regex_search(str, m, e);
		if (found)
		{
			cout << m.str() << endl;
		}
		else cout << "Not Found" << endl;
	}

	void test2()
	{
		string str = "123>Linjay@gmail.com<123"
			"123>Linfen@gmail.com<123";
		regex e("([[:w:]]+)@([[:w:]]+)\.com");
		smatch m;
		bool found = regex_search(str, m, e);
		if (found)
		{
			for (sregex_iterator it(str.begin(), str.end(), e), end_it; it != end_it; it++)
			{
				cout << it->str() << endl;
			}
		}
		else cout << "Not Found" << endl;
	}

	void test3()
	{
		string str = "123>Linjay@gmail.com<456";
		regex e("([[:w:]]+)@([[:w:]]+)\.com");
		smatch m;
		bool found = regex_search(str, m, e);
		if (found)
		{
			cout << "m.size() : " << m.size() << endl;
			for (size_t i = 0; i < m.size(); i++)
			{
				cout << "m.str(" << i << "): " << m.str(i) << endl;
			}
			cout << "m.prefix().str(): " << m.prefix().str() << endl;
			cout << "m.suffix().str(): " << m.suffix().str() << endl;
		}
		else cout << "Not Found" << endl;
	}

	void test4()
	{
		string str = "123>Linjay@gmail.com<123"
			"123>Linfen@qq.com<123"
			"123>Xiang@126.com<123";
		regex e("([[:w:]]+)@([[:w:]]+)\.com");
		cout << regex_replace(str, e, "$1 is on $2\n", 
			regex_constants::format_no_copy);
	}

	void test5()
	{
		string str = "123>Linjay@gmail.com<123"
			"123>Linfen@qq.com<123"
			"123>Xiang@126.com<123";
		regex e("([[:w:]]+)@([[:w:]]+)\.com");
		smatch m;
		bool found = regex_search(str, m, e);
		if (found)
		{
			for (sregex_iterator it(str.begin(), str.end(), e), 
				end_it; it != end_it; it++)
			{
				cout << it->format("$1 is on $2\n");
			}
		}
		else cout << "Not Found" << endl;
	}

	void test6()
	{
		const char* s1 = "hello\nworld!";
		const char* s2 = R"(hello\nworld!)";
		string s3 = R"(123\t123)";
		cout << s1 << endl;
		cout << s2 << endl;
		cout << s3 << endl;
	}

	void test7()
	{
		//string s1 = R"(abc"()"def)";       //错误
		string s1 = R"123(abc"()"def)123";   //正确
		cout << s1 << endl;
	}

	void test8()
	{
		string s1 = R"(123
456)";
		cout << s1 << endl;
	}

	void test9()
	{
		try
		{
			string s = "123456.456789";
			cout << "s=" << s << endl;
			cout.precision(16);
			cout << "stoi: " << stoi(s) << " to string: " << to_string(stoi(s)) << endl;
			cout << "stol: " << stol(s) << " to string: " << to_string(stol(s)) << endl;
			cout << "stoul: " << stoul(s) << " to string: " << to_string(stoul(s)) << endl;
			cout << "stoll: " << stoll(s) << " to string: " << to_string(stoll(s)) << endl;
			cout << "stoull: " << stoull(s) << " to string: " << to_string(stoull(s)) << endl;
			cout << "stof: " << stof(s) << " to string: " << to_string(stof(s)) << endl;
			cout << "stod: " << stod(s) << " to string: " << to_string(stod(s)) << endl;
			cout << "stold: " << stold(s) << " to string: " << to_string(stold(s)) << endl;
		}
		catch (const std::exception&)
		{
			cout << "string converting error" << endl;
		}
	}

	long double operator"" _mm(long double x) { return x / 1000; }
	long double operator"" _m(long double x) { return x; }
	long double operator"" _km(long double x) { return x * 1000; }
	void test10()
	{
		cout << 1.0_mm << endl; //0.001
		cout << 1.0_m << endl; //1
		cout << 1.0_km << endl; //1000
	}

	size_t operator"" _len(char const * str, size_t size) { return size; }//计算字符串size
	void operator"" _print(char const* str, size_t size) { cout << str << endl; }//打印输出
	struct mytype { unsigned long long m; };
	constexpr mytype operator"" _mytype(unsigned long long n) { return mytype{ n }; }//返回自定义类型
	void test11()
	{
		cout << "Hello world"_len << endl;
		"Hello world"_print;
		mytype y = 123_mytype;
		std::cout << y.m << endl;
	}


	struct Some {
		int some_i = 0;
		std::string some_str;
	};
	optional<Some> getSome(const std::vector<Some>& svec, int i) {
		auto iter = std::find_if(svec.begin(), svec.end(), [i](const Some& s) {
			return s.some_i == i;
		}
		);
		if (iter != svec.end()) {
			return *iter;
		}
		return nullopt;
	}
	void test12()
	{
	//	optional opt(std::vector<int>{ 0,1 });
	//	optional <vector<int>> opt{std::in_place, 0,1 };
	//	auto name = make_optional(vector<int>{1,2});
	//	auto name = make_optional<int>(1);
	//	auto name = make_optional(1);
	//	std::vector<Some> someVec;
	//	someVec.push_back({ 1, "1" });
	//	auto s_ptr = getSome(someVec, 1);
	//	if (s_ptr) {
	//		cout << s_ptr->some_str << endl; // “1”
	//	}
	//	s_ptr = getSome(someVec, 2);
	//	if (s_ptr) {
	//		cout << s_ptr->some_str << endl; // 不输出
	//	}
	}

	void test13()
	{
		//创建一个没有值的可选对象，必须指定包含类型
		optional<int> o1;
		optional<int> o2(std::nullopt);
		//传递值进行初始化，支持类型推导
		optional <string> o3( "string" );
		optional o4( "string" );
		optional <vector<string>> o5({ "string" });
		optional o6(vector<string>{"string"});
		//使用make_optional<>()构造
		auto o7 = make_optional("string");
		auto o8 = make_optional(vector<int>{1, 2, 3});
		o8->at(0);
		(*o8)[0];
	}

	void test14()
	{
		//{
		//	std::optional o{ 42 };
		//	if (o) {} // true
		//	if (!o) {} // false
		//	if (o.has_value()) {} // true
		//}

		//std::optional o{ std::pair{42, "hello"} };
		//auto p = *o; // initializes p as pair<int,string>
		//std::cout << o->first; // prints 42

		//std::optional<std::string> o{ "hello" };
		//std::cout << "*o: " << *o << endl; // OK: prints ”hello”
		//o = std::nullopt;
		//std::cout << "*o: " << *o;// undefined behavior

		std::optional<std::string> o{ "hello" };
		std::cout << "*o: " << o.value_or("no value") << endl; // OK: prints ”hello”
		o = std::nullopt;
		//std::cout << "*o: " << o.value();//没有包含值，它会抛出一个std::bad_optional_access异常
		std::cout << "*o: " << o.value_or("no value");// undefined behavior
	}

	using IntFloatString = std::variant<int, float, std::string>; // 定义支持int、float、string三个类型，并取一个别名
	void test15()
	{
		try
		{
			IntFloatString i = 10;
			cout << "std::get<int>(): " << std::get<int>(i) << endl;
			cout << "std::get<0>(): " << std::get<0>(i) << endl;

			IntFloatString f = 20.0f;
			cout << "std::get<float>(): " << std::get<float>(f) << endl;
			cout << "std::get<1>(): " << std::get<1>(f) << endl;

			IntFloatString s = "hello world";
			cout << "std::get<string>(): " << std::get<std::string>(s) << endl;
			cout << "std::get<2>(): " << std::get<2>(s) << endl;

			//错误用法
			//cout << std::get<double>(f) << endl;//编译阶段就会出错：没有double类型
			cout << std::get<1>(i) << endl;       //调试阶段抛出异常：int类型的标志位是0
		}
		catch (const std::exception& e)
		{
			cout << e.what();
		}
	}

	using Two = std::pair<double, double>;
	using Roots = std::variant<Two, double, void*>;

	Roots FindRoots(double a, double b, double c)
	{
		auto d = b * b - 4 * a*c;

		if (d > 0.0)
		{
			auto p = sqrt(d);
			return std::make_pair((-b + p) / 2 * a, (-b - p) / 2 * a);
		}
		else if (d == 0.0)
			return (-1 * b) / (2 * a);
		return nullptr;
	}

	void func()
	{
		cout << "Hello World" << endl;
	}
	void test16()
	{
		std::thread thread1(func);
		thread1.join();
	}

	void f1(int n) {}
	void f2(int& n){}
	struct foo {
		void bar(int arg){}
	};
	struct baz {
		void operator()(){}
	};
	void test17()
	{
		int n = 0;
		foo f;
		baz b;
		std::thread t1;                  // 未定义线程
		std::thread t2(f1, n + 1);       // 值传递
		std::thread t3(f2, std::ref(n)); // 引用传递，使用&无效
		std::thread t4(std::move(t3));   // t4 运行 f2(). t3 不再是一个线程
		std::thread t5(&foo::bar, &f, 1);// 参数可以是类成员函数
		std::thread t6(b);               // 还可以是函数对象
		t2.join();
		t4.join();
		t5.join();
		t6.join();
	}
	std::mutex _mutex;
	void printFunc(const std::string& str, const int& i)
	{
		std::lock_guard<std::mutex> guard(_mutex);
		std::cout << str << i << endl;
	}
	void func_1()
	{
		for (size_t i = 0; i < 100; i++)
		{
			printFunc("from sub thread: ", i);
		}
	}
	void test18()
	{
		thread t1(func_1);
		for (size_t i = 0; i < 100; i++)
		{
			printFunc("from main thread: ", i);
		}
		t1.join();
	}

}