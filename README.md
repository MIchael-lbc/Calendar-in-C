# Calendar-in-C

  =    ==  =  =  =  =  ==  ==    ==    ==  =  ==  =  ===  	==	=	
	Perfect question 👏 — let’s explain **what a leap year** is in both **simple words** and **programming logic** so you never forget it.

---

### 🌍 **Real-world meaning**

A **leap year** is a year that has **366 days instead of 365**.
👉 The **extra day** is added to **February**, so it has **29 days instead of 28**.

Why?
Because the Earth actually takes about **365.25 days** to orbit the sun.
So every 4 years, we add one extra day to keep the calendar accurate.

---

### 📅 **Leap year rules**

A year is a **leap year** if:

1. It is **divisible by 4**,
2. But **not divisible by 100**,
3. Except if it is also **divisible by 400** (then it *is* a leap year).

---

### ✅ **Examples**

| Year | Divisible by 4 | Divisible by 100 | Divisible by 400 | Leap Year? |
| ---- | -------------- | ---------------- | ---------------- | ---------- |
| 2020 | ✅              | ❌                | —                | ✅ Yes      |
| 1900 | ✅              | ✅                | ❌                | ❌ No       |
| 2000 | ✅              | ✅                | ✅                | ✅ Yes      |
| 2024 | ✅              | ❌                | —                | ✅ Yes      |
| 2025 | ❌              | —                | —                | ❌ No       |

---

### 💻 **In C code**

Here’s how you usually check it:

```c
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1; // leap year
    else
        return 0; // not leap year
}
```

So:

* `isLeapYear(2024)` → returns `1`
* `isLeapYear(2025)` → returns `0`

---

### 💡 **Memory trick**

Think of it like:

> “Every 4 years is a leap year…
> except century years (like 1900)…
> unless divisible by 400 (like 2000).”

---

If you want, I can show you **how leap years affect your `days_in_month[]` array** — specifically how to automatically make February = 29 days only when it’s a leap year.
Do you want that example?

=	=	=	=	=	=	=	=	==	=	=	=	==	=	=		=	=	=	=	=	=	==	=	=	==	=	
كلمة **leap year** بالإنجليزية معناها **سنة كبيسة** بالعربية.

🗓️ **السنة الكبيسة** هي السنة التي يكون فيها شهر فبراير **29 يومًا** بدلًا من 28 يومًا.
وتأتي مرة كل **أربع سنوات** تقريبًا.
	=	=	==	=		==		=	=	==	=		==		=	=		=	=	==	=		==	==		=	


Great question 👏

The **benefit of calculating a leap year** is to make sure the **calendar stays accurate** with the **real time of the Earth’s movement around the Sun** 🌍☀️

Let’s explain simply 👇

---

### 🧠 What is happening:

* The Earth takes about **365.25 days** to orbit the Sun — **not exactly 365**.
* That extra **0.25 day = 6 hours** builds up.
* After **4 years**, those extra 6 hours × 4 = **24 hours = 1 full day**.
* So, we **add 1 extra day (Feb 29)** every 4 years.
  → That year is called a **leap year**.

---

### 📅 Why your program needs to calculate leap years:

If you are building a **calendar program**, you need to know:

* February has **28 days** normally.
* But in leap years, February has **29 days**.

So, the line:

```c
days_in_month[2] = 29;
```

is only correct **if** the year is a leap year.
That’s why your code checks for leap years — to show the **right number of days** in the calendar.

---

### ✅ Example:

| Year | Leap Year? | Days in February |
| ---- | ---------- | ---------------- |
| 2023 | ❌ No       | 28               |
| 2024 | ✅ Yes      | 29               |
| 2025 | ❌ No       | 28               |

---

Would you like me to show you the **C function** that checks if a year is leap year or not?

	======	==	=	=	=	=	=	==	=	=	==	=	=	=		==	=	=	===	=	=	=	==	=	=	=	
	✅ Exactly! Yes — **2028 will be a leap year.**

Here’s why 👇

A year is a **leap year** if:

```c
(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)
```

Now check step by step for **2028**:

1. `2028 % 4 == 0` → ✅ true
2. `2028 % 100 != 0` → ✅ true
3. So the first condition `(year % 4 == 0 && year % 100 != 0)` is true → ✅
4. That means 2028 **is a leap year.**

🗓️ February 2028 will have **29 days**.


		=	=	=	=		=	=		=	=	=	=	=	=	

		Absolutely! Let’s make it **very clear**. 😄

In programming (like in your calendar program), we often **assign numbers to weekdays** so the computer can understand them. This is usually called the **day code**.

---

### 📅 Standard Day Codes

| Day of Week | Number (day code) |
| ----------- | ----------------- |
| Sunday      | 0                 |
| Monday      | 1                 |
| Tuesday     | 2                 |
| Wednesday   | 3                 |
| Thursday    | 4                 |
| Friday      | 5                 |
| Saturday    | 6                 |

---

### ✅ How it works in code

```c
int dayCode = 3;  // Example
```

* `dayCode = 3` → Wednesday
* `dayCode = 0` → Sunday
* `dayCode = 6` → Saturday

---

### 💻 Example: printing day names from code

```c
#include <stdio.h>

int main() {
    char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    
    for (int i = 0; i < 7; i++) {
        printf("Day code %d = %s\n", i, days[i]);
    }

    return 0;
}
```

**Output:**

```
Day code 0 = Sunday
Day code 1 = Monday
Day code 2 = Tuesday
Day code 3 = Wednesday
Day code 4 = Thursday
Day code 5 = Friday
Day code 6 = Saturday
```

---

💡 **Summary**:

* Computers don’t use “Sunday” or “Monday” directly.
* They use **numbers 0–6** (day code).
* Later you can **map the number to the day name** using an array like above.

---

If you want, I can show you **how to use this in your full calendar program** so it prints **Sun, Mon, Tue…** automatically for every month.

Do you want me to do that?

