#pragma  warning (disable:4996)
#include "practices.h"
#include <iostream>
#include <optional>
#include <variant>
#include <regex>
#include <thread>
#include <mutex>
#include <deque>
#include <future>
#include <chrono>
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
		for (sregex_iterator it(str.begin(), str.end(), e), end_it; it != end_it; it++)
		{
			cout << it->str() << endl;
		}
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
			regex_constants::format_no_copy/*��־λ����ʾ���������������δƥ��Ĳ���*/);
	}

	void test5()
	{
		string str = "123>Linjay@gmail.com<123"
			"123>Linfen@qq.com<123"
			"123>Xiang@126.com<123";
		regex e("([[:w:]]+)@([[:w:]]+)\.com");
		for (sregex_iterator it(str.begin(), str.end(), e),
			end_it; it != end_it; it++)
		{
			cout << it->format("$1 is on $2\n");
		}
	}

	void test6()
	{
		string s1 = "hello\nworld!";
		string s2 = R"(hello\nworld!)";
		string s3 = R"(123\t123)";
		string s4 = R"(123
456)";
		cout << s1 << endl;
		cout << s2 << endl;
		cout << s3 << endl;
		cout << s4 << endl;
	}

	void test7()
	{
		//string s1 = R"(abc"()"def)";       //����
		string s1 = R"123(abc"()"def)123";   //��ȷ
		string s2 = R"123(abc()def)123";	 //��ȷ
		string s3 = R"123((abc()def))123";   //��ȷ
		cout << s1 << endl;
		cout << s2 << endl;
		cout << s3 << endl;
	}

	void test8()
	{
		string s1 = R"(123
456)";
		cout << s1 << endl;
	}

	void test9()
	{
		string s = "123456.456789";
		cout << "s=" << s << endl;
		cout.precision(16);
		cout << "stoi: " << stoi(s) << ", to_string: " << to_string(stoi(s)) << endl;
		cout << "stol: " << stol(s) << ", to_string: " << to_string(stol(s)) << endl;
		cout << "stoul: " << stoul(s) << ", to_string: " << to_string(stoul(s)) << endl;
		cout << "stoll: " << stoll(s) << ", to_string: " << to_string(stoll(s)) << endl;
		cout << "stoull: " << stoull(s) << ", to_string: " << to_string(stoull(s)) << endl;
		cout << "stof: " << stof(s) << ", to_string: " << to_string(stof(s)) << endl;
		cout << "stod: " << stod(s) << ", to_string: " << to_string(stod(s)) << endl;
		cout << "stold: " << stold(s) << ", to_string: " << to_string(stold(s)) << endl;
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

	size_t operator"" _len(char const * str, size_t size) { return size; }//�����ַ���size
	void operator"" _print(char const* str, size_t size) { cout << str << endl; }//��ӡ���
	struct mytype { unsigned long long m; };
	constexpr mytype operator"" _mytype(unsigned long long n) { return mytype{ n }; }//�����Զ�������
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
	//bool getSome(Some& res, std::vector<Some>& svec, int i)
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
	//		cout << s_ptr->some_str << endl; // ��1��
	//	}
	//	s_ptr = getSome(someVec, 2);
	//	if (s_ptr) {
	//		cout << s_ptr->some_str << endl; // �����
	//	}
	}

	void test13()
	{
		//����һ��û��ֵ�Ŀ�ѡ���󣬱���ָ����������
		optional<int> o1;
		optional<int> o2(std::nullopt);
		//����ֵ���г�ʼ����֧�������Ƶ�
		optional <string> o3( "string" );
		optional o4( "string" );
		optional <vector<string>> o5({ "string" });
		optional o6(vector<string>{"string"});
		//ʹ��make_optional<>()����
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
		//std::cout << "*o: " << *o << endl; // OK: prints ��hello��
		//o = std::nullopt;
		//std::cout << "*o: " << *o;// undefined behavior

		std::optional<std::string> o{ "hello" };
		std::cout << "*o: " << o.value_or("no value") << endl; // OK: prints ��hello��
		o = std::nullopt;
		//std::cout << "*o: " << o.value();//û�а���ֵ�������׳�һ��std::bad_optional_access�쳣
		std::cout << "*o: " << o.value_or("no value");// undefined behavior
	}

	using IntFloatString = std::variant<int, float, std::string>; // ����֧��int��float��string�������ͣ���ȡһ������
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

			//�����÷�
			//cout << std::get<double>(f) << endl;//����׶ξͻ����û��double����
			cout << std::get<1>(i) << endl;       //���Խ׶��׳��쳣��int���͵ı�־λ��0
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
		std::thread t1;                  // δ�����߳�
		std::thread t2(f1, n + 1);       // ֵ����
		std::thread t3(f2, std::ref(n)); // ���ô��ݣ�ʹ��&��Ч
		std::thread t4(std::move(t3));   // t4 ���� f2(). t3 ������һ���߳�
		std::thread t5(&foo::bar, &f, 1);// �������������Ա����
		std::thread t6(b);               // �������Ǻ�������
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

	mutex g_lock; //ȫ�ֻ���������#include <mutex>
	void printer(const char *str) { // ��ӡ�� 
		lock_guard<std::mutex> locker(g_lock);
		while (*str != '\0') {
			cout << *str;
			str++;
			this_thread::sleep_for(chrono::microseconds(5));
		}
		cout << endl;
	}
	void func1() {  //���߳�
		printer("hello");
	}
	void test19()
	{
		thread t1(func1);
		printer("world");
		t1.join();
	}


	void subThread()
	{
		std::cout << "Starting sub thread.\n";
		std::this_thread::sleep_for(std::chrono::microseconds(20));
		std::cout << "Exiting sub thread.\n";
	}
	void test20()
	{
		std::cout << "Starting call thread.\n";
		std::thread t(subThread);
		if(t.joinable()) t.join();
		std::this_thread::sleep_for(std::chrono::microseconds(10));
		std::cout << "Exiting call thread.\n";
		std::this_thread::sleep_for(std::chrono::microseconds(100));//�ȴ����߳̽���
	}

	std::deque<int> q;						//˫�˶��б�׼����ȫ�ֱ���
	std::mutex mu;							//������ȫ�ֱ���
	std::condition_variable cond;           //ȫ����������
	void function_1() {//�����ߣ������з�������
		for (size_t i = 10; i > 0; i--) {
			std::unique_lock<std::mutex> locker(mu);
			q.push_front(i);			//�������������
			locker.unlock();
			cond.notify_one();          //��һ���ȴ��̷߳��������������㡱��֪ͨ
			//cond.notify_all();          //�����ȴ��̷߳��������������㡱��֪ͨ
			std::this_thread::sleep_for(std::chrono::seconds(1));		//��ʱ1��
		}
	}
	void function_2() {//�����ߣ��Ӷ�����ȡ����
		int data = 0;
		while (data != 1) {
			std::unique_lock<std::mutex> locker(mu);
			if (!q.empty()) {			//�ж϶����Ƿ�Ϊ��
				while (q.empty())       //�ж϶����Ƿ�Ϊ�գ����Ѻ��ٴμ����У�����Ϊ�ռ������ߵȴ�����ֹ��ٻ���
					cond.wait(locker);  //���������������������Եȴ�֪ͨ�����ѣ������Ѻ�����Ա�����������
				data = q.back();
				q.pop_back();			//���ݳ���������
				locker.unlock();
				std::cout << "t2 got a value from t1: " << data << std::endl;
			}
		}
	}
	void test21()
	{
		std::thread t1(function_1);
		std::thread t2(function_2);
		t1.join();
		t2.join();
	}
	
	string function_3()
	{
		this_thread::sleep_for(chrono::seconds(5));
		return "name";
	}
	void test22()
	{
		auto accumulate_future = std::async(std::launch::async, function_3);
		cout << "get begin" << endl;
		this_thread::sleep_for(chrono::seconds(5));
		cout << "sleep for 5 seconds" << endl;
		cout << accumulate_future.get() << endl;
		cout << "get end" << endl;
	}

	atomic<long> total = { 0 };
	mutex lock;
	void func_thread() {
		for (int i = 0; i < 1000000; ++i) {
			total += 1;// ��ȫ�����ݽ�����������
		}
	}
	void test23()
	{
		clock_t start = clock();    // ��ʱ��ʼ
		thread t1(func_thread);
		thread t2(func_thread);
		t1.join();
		t2.join();
		clock_t end = clock();    // ��ʱ����
		cout << "total = " << total << endl;
		cout << "time = " << end - start << " ms\n";
	}

	void test24()
	{
		//��ȡ��epoch����������
		time_t now = time(NULL);
		cout << "1970��Ŀǰ����������" << now << endl;

		//��nowת��Ĭ���ַ�����ʽ
		char* dt = ctime(&now);
		cout << "Ĭ�ϸ�ʽ�������ʱ�����ڣ�" << dt;

		//��nowת��tm�ṹ
		tm* ltm = localtime(&now);
		cout << "tm�ṹ�������ʱ�����ڣ�" <<
			1900 + ltm->tm_year << "��" << 1 + ltm->tm_mon << "��" << ltm->tm_mday << "��" 
			<< ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;

		//��ltmת���Զ����ʽ
		char buffer[80];
		strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", ltm);
		printf("�Զ����ʽ���������ʱ�����ڣ�|%s|\n", buffer);
	}

	void test25()
	{
		//��ȡ��epoch����������
		time_t now = time(NULL);
		cout << "1970��Ŀǰ����������" << now << endl;

		//chrono��ȡʱ��
		auto now2 = chrono::system_clock::now();
		cout << "1970��Ŀǰ����������" << chrono::duration_cast<chrono::seconds>(now2.time_since_epoch()).count() << endl;

		//chrono��ȡʱ��
		auto now3 = chrono::steady_clock::now();
		cout << "1970��Ŀǰ����������" << chrono::duration_cast<chrono::minutes>(now3.time_since_epoch()).count() << endl;
	}

	void test26()
	{
		//��ȡ��ǰʱ��
		using namespace chrono;
		typedef duration<int, ratio<60 * 60 * 24 * 7>> weeks_type;//�Զ���һ��ʱ����������
		time_point now = system_clock::now();
		auto now_seconds = time_point_cast<seconds>(now);//ת������Ϊ��λ��ʱ���
		auto now_weeks = time_point_cast<weeks_type>(now);//ת��������Ϊ��λ��ʱ���
		auto nowDuration = now.time_since_epoch();
		cout << "��Ԫ��Ŀǰ����ʱ�䣺" << now.time_since_epoch().count() << endl;
		cout << "��Ԫ��Ŀǰ����������" << now_seconds.time_since_epoch().count() << endl;
		cout << "��Ԫ��Ŀǰ������������" << now_weeks.time_since_epoch().count() << endl;

		//time_pointת��time_t
		auto timet = chrono::system_clock::to_time_t(now);
		char* dt = ctime(&timet);
		cout << "����ʱ�����ڣ�" << dt;
	}

	void test27()
	{
		string str1 = "abc123", str2 = "###ABC123";
		regex r("[a-z0-9]+");//����ĸ����������ɵ�һ�������ַ�����

		//ʹ��regex_match���ƥ��
		cout << "str1 match result: " << regex_match(str1, r) << endl;
		cout << "str2 match result: " << regex_match(str2, r) << endl;

		//ʹ��regex_search���ƥ��
		cout << "str1 match result: " << regex_search(str1, r) << endl;
		cout << "str2 match result: " << regex_search(str2, r) << endl;
	}

	void test28()
	{
		using IntFloatString = std::variant<int, float, std::string>; // ����֧��int��float��string�������ͣ���ȡһ������
		try
		{
			vector<IntFloatString> vecs{ 10, 20.f, "hello world" };
			for (size_t i = 0; i < vecs.size(); i++)
			{
				if (std::get_if<int>(&vecs[i]))
					cout << "std::get<int>(): " << std::get<int>(vecs[i]) << endl;
				if (std::get_if<float>(&vecs[i]))
					cout << "std::get<float>(): " << std::get<float>(vecs[i]) << endl;
				if (std::get_if<string>(&vecs[i]))
					cout << "std::get<string>(): " << std::get<string>(vecs[i]) << endl;
				if (std::get_if<0>(&vecs[i]))
					cout << "std::get<0>(): " << std::get<0>(vecs[i]) << endl;
				if (std::get_if<1>(&vecs[i]))
					cout << "std::get<1>(): " << std::get<1>(vecs[i]) << endl;
				if (std::get_if<2>(&vecs[i]))
					cout << "std::get<2>(): " << std::get<2>(vecs[i]) << endl;
			}

			//�����÷�
			IntFloatString i = 10;
			//cout << std::get<double>(i) << endl;//����׶ξͻ����û��double����
			cout << std::get<1>(i) << endl;       //���Խ׶��׳��쳣��int���͵ı�־λ��0
		}
		catch (const std::exception& e)
		{
			cout << e.what();
		}
	}

	void test29()
	{

	}

}