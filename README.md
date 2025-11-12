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
	==	=		=	==			=	=	=	=	=	===	=	=	===	=	==	=	=	
	=	=	==	=		=	==		==	=	=	=	==	=	==			=	=	
	No worries! 😅 Let’s **slow down** and go super **step by step**, in plain simple words.

We are talking about this function:

```c
int determineDayCode(int year)
{
    int daycode;
    int d1, d2, d3;

    d1 = (year - 1) / 4;
    d2 = (year - 1) / 100;
    d3 = (year - 1) / 400;

    daycode = (year + d1 - d2 + d3) % 7;

    return daycode;
}
```

---

### 1️⃣ What is the **goal** of this function?

It wants to tell you **which day of the week January 1st of that year falls on**.

* Sunday → 0
* Monday → 1
* Tuesday → 2
* …
* Saturday → 6

Example:

* If it returns `3`, then **Jan 1 is Wednesday**.

---

### 2️⃣ Why do we need the math?

Every year, the first day of the year moves forward because:

* 1 normal year = 365 days → 52 weeks + 1 day

  * So if Jan 1 was Monday this year → next year it will be **Tuesday**
* Leap year = 366 days → 52 weeks + 2 days

  * So if Jan 1 was Monday → next year it will be **Wednesday**

The formula calculates **all these extra days** so we know the weekday for Jan 1 of any year.

---

### 3️⃣ What do `d1`, `d2`, `d3` mean?

```c
d1 = (year - 1) / 4;
```

* Counts how many leap years happened **every 4 years**.

```c
d2 = (year - 1) / 100;
```

* Subtracts the years divisible by 100 because **century years are not leap years**.

```c
d3 = (year - 1) / 400;
```

* Adds back the years divisible by 400 because **every 400th year is a leap year**.

---

### 4️⃣ Final calculation:

```c
daycode = (year + d1 - d2 + d3) % 7;
```

* Adds the year itself + extra days from leap years (`d1`)
* Subtracts the century exceptions (`d2`)
* Adds back 400-year corrections (`d3`)
* `% 7` → remainder when divided by 7 → gives **day of week**

---

### 5️⃣ Example (super simple)

Year = 2025

```
d1 = (2024)/4 = 506   → leap years
d2 = (2024)/100 = 20  → century non-leap
d3 = (2024)/400 = 5   → 400-year leap
daycode = (2025 + 506 - 20 + 5) % 7
daycode = 2516 % 7
daycode = 6
```

✅ Day code 6 = Saturday → **Jan 1, 2025 is Saturday**

---

### 6️⃣ Key thing to remember

* This function **does NOT print anything**
* It **just tells you the weekday number** (0–6) for Jan 1 of any year
* Later you can use this to **print a calendar correctly**

---

If you want, I can **draw a very simple picture** showing **how the days move every year** and how this formula works visually — that will make it click immediately.

Do you want me to do that?
	=	=	==	=	=	=	=	=	==		=	=	==	=	=	=	=	=	=	===	=	==	=		==	=	=	==	=	=	=	=	=	=	=	==	==	=	==	==	=	=	=	==	==	
	Ah! Now we’re talking 🔥 — you want to understand **where the formula comes from mathematically**. Let’s go **step by step**, very clear, so you actually *see the logic*.

The formula is:

```
daycode = (year + (year-1)/4 - (year-1)/100 + (year-1)/400) % 7
```

It calculates the **day of the week for Jan 1 of a given year**.

---

## 1️⃣ Understanding the problem

We know:

* A **week has 7 days**.
* The **first day of the year moves forward** depending on how many days were in the previous years.

Each normal year = 365 days → 52 weeks + 1 extra day → shifts the first day by **1**.
Each leap year = 366 days → 52 weeks + 2 extra days → shifts the first day by **2**.

So to find Jan 1 of year `Y`, we need:

1. Count **how many extra days** happened from all previous years (1970 or 1 AD)
2. Use `% 7` because weeks repeat every 7 days

---

## 2️⃣ Counting leap years

Leap years rules:

1. Divisible by 4 → usually leap
2. Divisible by 100 → not leap
3. Divisible by 400 → leap again

So for all previous years (`year-1`), we count:

```
(year-1)/4   → all years divisible by 4 → add 1 extra day
(year-1)/100 → subtract century years → remove 1 day
(year-1)/400 → add back 400-year centuries → add 1 day
```

This is exactly **d1 - d2 + d3** in the formula.

---

## 3️⃣ Adding the year itself

```
daycode = year + d1 - d2 + d3
```

Why add `year`?

* Each normal year contributes **1 extra day** because 365 = 52 weeks + 1
* So `year` itself counts how many normal “1-day shifts” happened.

---

## 4️⃣ Mod 7

We only care about **weekday numbers 0–6**, so:

```
daycode % 7
```

* `0` → Sunday
* `1` → Monday
* …
* `6` → Saturday

The `% 7` “wraps around” every week.

---

## 5️⃣ Putting it all together

**Step by step (for example, 2025)**:

1. `year = 2025`
2. `(year-1)/4 = 2024/4 = 506` → leap years
3. `(year-1)/100 = 2024/100 = 20` → remove century non-leaps
4. `(year-1)/400 = 2024/400 = 5` → add back 400-year leaps

```
total shift = year + d1 - d2 + d3
            = 2025 + 506 - 20 + 5
            = 2516
```

```
daycode = 2516 % 7 = 6
```

✅ Day code 6 = Saturday → Jan 1, 2025 is Saturday

---

### 6️⃣ Why this formula works

* **Year** → adds 1-day shifts per normal year
* **d1** → adds 1-day shifts for all leap years
* **d2** → removes the false leap years (century)
* **d3** → adds back the leap years divisible by 400
* `%7` → converts the total number of extra days into a **weekday**

Basically, the formula **counts all the extra days from the previous years** and converts that to a day of the week.

---

If you want, I can **draw a small timeline diagram** showing **how normal years, leap years, centuries, and 400-year leaps shift the day** — it will make this formula 100% intuitive.

Do you want me to do that?
=		==		=	==		==	=	=	=	=	=		=		=	=	=	=	=	=	=	==		=	==	=	=	=	=	=	==	=	=	=	==	=	=	=	==			=	==	
Absolutely! Let’s go **line by line** and explain exactly what the code does in **plain, beginner-friendly terms**, using your `calendar` function. I’ll also explain **why we write each line**.

---

### Your function:

```c
void calendar(int year, int daycode) {
    int month, day;
```

* `void` → the function **doesn’t return a value**, it only prints the calendar.
* `int year` → the year to print (e.g., 2025).
* `int daycode` → the **weekday of Jan 1** (0 = Sunday, 1 = Monday … 6 = Saturday).
* `int month, day;` → variables for **looping through months and days**.

---

### Loop through all months

```c
for (month = 1; month <= 12; month++) {
```

* This loop **goes from January (1) to December (12)**.
* For each month, we will print the **month name**, **weekdays**, and **dates**.

---

### Print month name

```c
printf("%s\n", months[month - 1]);
```

* `months` is an array holding month names: `"January", "February", ...`.
* Arrays in C **start at 0**, so for January (`month = 1`) we need `month - 1`.
* This prints the **name of the current month**.

---

### Print weekdays header

```c
printf("Sun Mon Tue Wed Thu Fri Sat\n");
```

* Prints **the days of the week** at the top, like a real calendar.

---

### Print spaces before the first date

```c
for (day = 0; day < daycode; day++) {
    printf("    "); // 4 spaces for alignment
}
```

* `daycode` tells **where the first day of the month starts**.
* Example: if `daycode = 3` → month starts on Wednesday → print **3 empty spaces** so `1` appears under Wednesday.
* `printf("    ")` → 4 spaces, to align numbers under weekdays.

---

### Print all dates of the month

```c
for (day = 1; day <= days_in_month[month]; day++) {
    printf("%3d ", day);
```

* Loops from **1 to the number of days in the month**.
* `days_in_month[month]` → gives how many days in the current month.
* `%3d ` → prints numbers in **3-character width**, so all dates align in columns.

---

### Move to next line after Saturday

```c
if ((day + daycode) % 7 == 0)
    printf("\n");
```

* `(day + daycode)` → calculates **position of the current day in the week**.
* `% 7 == 0` → if it is **Saturday**, we print a new line to start the next week.

---

### End of month separator

```c
printf("\n----------------------------\n");
```

* Prints a **line to separate months visually**.

---

### Update daycode for the next month

```c
daycode = (daycode + days_in_month[month]) % 7;
```

* For the **next month**, the first day depends on how many days were in this month.
* `% 7` → makes sure the daycode is always 0–6 (Sunday → Saturday).

---

### Summary (flow)

1. **Loop over months**
2. **Print month name**
3. **Print weekdays header**
4. **Print empty spaces** until the first day
5. **Print all dates** in order
6. **Move to next line after Saturday**
7. **Update daycode** for the next month

---

💡 **Analogy**:

* Think of a **row of boxes for the week**: `Sun Mon Tue ... Sat`
* Put numbers in boxes
* When you reach the last box → move to the next row
* At the end of the month, count **how many boxes were filled** → that tells **where the next month starts**

---

If you want, I can **draw a visual example of January with daycode and spaces** so you can **see exactly how the numbers and daycode work**.

Do you want me to do that?
=	=	==	=	=	==	=		=		=	==	=		===		=	==	=	=	==		=
No worries! 😅 Let’s slow down and make it **super simple**, step by step, without confusing words. We’ll use a **very easy analogy**.

---

### Imagine a calendar

Think of **a calendar as a grid**:

```
Sun Mon Tue Wed Thu Fri Sat
          1   2   3   4
  5   6   7   8   9  10  11
...
```

* Each column = a day of the week
* Each row = one week
* `daycode` = tells **where the first day of the month starts**

---

### Step 1: Print month name

```c
printf("%s\n", months[month - 1]);
```

* Shows **January, February, etc.**
* Example: prints **"January"**

---

### Step 2: Print weekdays

```c
printf("Sun Mon Tue Wed Thu Fri Sat\n");
```

* Shows **Sun, Mon … Sat** on top like a real calendar

---

### Step 3: Print empty spaces before first day

```c
for (day = 0; day < daycode; day++) {
    printf("    ");
}
```

* If **month starts on Wednesday**, `daycode = 3`
* We print **3 empty spaces** so "1" appears under Wednesday

---

### Step 4: Print all dates

```c
for (day = 1; day <= days_in_month[month]; day++) {
    printf("%3d ", day);
```

* Loops through **all days of that month**
* `%3d` → makes all numbers **line up in columns**

---

### Step 5: Start new line after Saturday

```c
if ((day + daycode) % 7 == 0)
    printf("\n");
```

* Counts **days in the week**
* When it reaches **Saturday**, start a **new line**

---

### Step 6: Update daycode for next month

```c
daycode = (daycode + days_in_month[month]) % 7;
```

* This finds **the first day of next month**
* Example: if current month has 31 days and started on Wednesday (`daycode=3`):

```
Next month first day = (3 + 31) % 7 = 34 % 7 = 6 → Saturday
```

---

### Analogy to understand

* Imagine a **row of boxes** for a week: `Sun Mon Tue Wed Thu Fri Sat`
* You put numbers in the boxes
* When you reach the last box (Saturday), move to the next row
* At the end of the month, count how many boxes you filled → that decides **where next month starts**

---

### TL;DR

1. Print **month name**
2. Print **days of week**
3. Print **spaces until first day**
4. Print **all dates**
5. Start a **new line after Saturday**
6. Update **first day of next month**

---

If you want, I can **draw a small picture of one month** showing **how spaces, numbers, and daycode work** — it will make it click immediately.

Do you want me to do that?
	==		==	=	=	=	=		==	=	==	=	=	=	=	=	==	=	=	=	=	=	=		==	==	=	=		=	==	=		=	=	=	=		==	==			=	=	=
