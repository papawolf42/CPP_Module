#include <iostream>

class Date {
	int year_;
	int month_;
	int day_;

	public:
	void SetDate(int year, int month, int date) {
		year_ = year;
		month_ = month;
		day_ = date;
	}
	void AddDay(int inc) {
		day_ += inc;
		while (1)
		{
			if (day_ > 31 && (month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12)) {
				day_ -= 31;
				AddMonth(1);
			}
			else if (day_ > 30 && (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11)) {
				day_ -= 30;
				AddMonth(1);
			}
			else if ((month_ == 2) && day_ > 28 + IsLeapYear()) {
				day_ -= 28 + IsLeapYear();
				AddMonth(1);
			}
			else {
				break;
			}
		}
	}
	void AddMonth(int inc) {
		month_ += inc;
		while (1) {
			if (month_ > 12) {
				month_ -= 12;
				AddYear(1);
			}
			else {
				break;
			}
		}
	}
	void AddYear(int inc) {
		year_ += inc;
	}

	void ShowDate() {
		std::cout << year_ << "년 " << month_ << "월 " << day_ << "일" << std::endl;
	}
	int IsLeapYear() {
		if (year_ % 4 == 0 && (year_ % 100 != 0) || year_ % 400 == 0)
			return (1);
		else
			return (0);
	}

	Date(int year, int month, int day) {
		year_ = year;
		month_ = month;
		day_ = day;
	}
};

int main(int argc, char const *argv[])
{
	// Date date;

	Date day(2000, 2, 28);
	day.AddDay(1);
	day.ShowDate();
	day.AddDay(1);
	day.ShowDate();
	day.AddDay(1);
	day.ShowDate();
	return 0;
}
