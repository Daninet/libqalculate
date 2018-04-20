/*
    Qalculate    

    Copyright (C) 2018  Hanna Knutsson (hanna.knutsson@protonmail.com)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
*/

#ifndef QALCULATE_DATE_TIME_H
#define QALCULATE_DATE_TIME_H

#include "Number.h"
#include "includes.h"

class QalculateDateTime {
	protected:
		long int i_year;
		long int i_month;
		long int i_day;
		long int i_hour;
		long int i_min;
		Number n_sec;
		bool b_time;
	public:
		QalculateDateTime();
		QalculateDateTime(long int initialyear, int initialmonth, int initialday);
		QalculateDateTime(const Number &initialtimestamp);
		QalculateDateTime(string date_string);
		QalculateDateTime(const QalculateDateTime &date);
		bool operator > (const QalculateDateTime &date2) const;
		bool operator < (const QalculateDateTime &date2) const;
		bool operator >= (const QalculateDateTime &date2) const;
		bool operator <= (const QalculateDateTime &date2) const;
		bool operator != (const QalculateDateTime &date2) const;
		bool operator == (const QalculateDateTime &date2) const;
		bool isFutureDate() const;
		bool isPastDate() const;
		void setToCurrentDate();
		void setToCurrentTime();
		bool set(long int newyear, int newmonth, int newday);
		bool set(const Number &newtimestamp);
		bool set(string date_string);
		void set(const QalculateDateTime &date);
		string toISOString() const;
		string toLocalString() const;
		string print(const PrintOptions &po = default_print_options) const;
		long int year() const;
		long int month() const;
		long int day() const;
		long int hour() const;
		long int minute() const;
		const Number &second() const;
		void setYear(long int newyear);
		bool setTime(long int ihour, long int imin, const Number &nsec);
		bool timeIsSet() const;
		bool addDays(const Number &ndays);
		bool addMonths(const Number &nmonths);
		bool addYears(const Number &nyears);
		bool addHours(const Number &nhours);
		bool addMinutes(const Number &nminutes, bool remove_leap_second = true, bool convert_to_utc = true);
		bool addSeconds(const Number &seconds, bool count_leap_seconds = true, bool convert_to_utc = true);
		bool add(const QalculateDateTime &date);
		int weekday() const;
		int week(bool start_sunday = false) const;
		int yearday() const;
		Number timestamp(bool reverse_utc = false) const;
		Number secondsTo(const QalculateDateTime &date, bool count_leap_seconds = true, bool convert_to_utc = true) const;
		Number daysTo(const QalculateDateTime &date, int basis = 1, bool date_func = true, bool remove_leap_seconds = true) const;
		Number yearsTo(const QalculateDateTime &date, int basis = 1, bool date_func = true, bool remove_leap_seconds = true) const;
		
		string parsed_string;
};

#endif