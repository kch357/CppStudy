#include <iostream>

class Date {
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    private:
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
            while (day_ > month_days[month_ -1]) {
                day_ -= month_days[month_ - 1];
                month_ += 1;
                if (month_ == 13) {
                    month_ = 1;
                    year_ += 1;
                }
            }
        }
        void AddMonth(int inc) {
            year_ += (inc + month_) / 12;
            month_ = (inc + month_) % 12;
            if (month_ == 0) {
                year_ -= 1;
                month_ = 12;
            }
        }
        void AddYear(int inc) {
            year_ += inc;
        }

        void ShowDate() {
            std::cout << "Year : " << year_ << std::endl
            << "Month : " << month_ << std::endl
            << "Day : " << day_ << std::endl; 
        }
};

int main() {
    std::cout << "날짜 설정 : 1" << std::endl
    << "일 덧셈 계산 : 2" << std::endl
    << "월 덧셈 계산 : 3" << std::endl
    << "년 덧셈 계산 : 4" << std::endl
    << "날짜 보기 : 5" << std::endl
    << "나가기 : 0" << std::endl;
    
    int input;
    Date date;
    while (1) {
        std::cout << std::endl << "입력하세요 : ";
        std::cin >> input;
        if (input == 0) break;
        if (input == 1) {
            int input_year;
            int input_month;
            int input_day;
            std::cout << "날짜를 설정하세요." << std::endl
            << "Year : ";
            std::cin >> input_year;
            std::cout << "Month : ";
            std::cin >> input_month;
            std::cout << "Day : ";
            std::cin >> input_day;
            date.SetDate(input_year, input_month, input_day);
        }
        if (input == 2) {
            int inc;
            std::cout << "며칠을 더할까요? : ";
            std::cin >> inc;
            date.AddDay(inc);
            std::cout << "설정이 완료되었습니다." << std::endl;
        }
        if (input == 3) {
            int inc;
            std::cout << "몇 달을 더할까요? : ";
            std::cin >> inc;
            date.AddMonth(inc);
            std::cout << "설정이 완료되었습니다." << std::endl;
        }
        if (input == 4) {
            int inc;
            std::cout << "몇 년을 더할까요? : ";
            std::cin >> inc;
            date.AddYear(inc);
            std::cout << "설정이 완료되었습니다." << std::endl;
        }
        if (input == 5)
            date.ShowDate();
    }

    return 0;
}