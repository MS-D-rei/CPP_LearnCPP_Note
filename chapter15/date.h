#ifndef DATE_H
#define DATE_H

class Date {
   private:
    int m_year{};
    int m_month{};
    int m_day{};

   public:
    Date(int year, int month, int day);

    void setDate(int year, int month, int day);

    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const { return m_day; }

    void print() const;
};

#endif  // DATE_H
