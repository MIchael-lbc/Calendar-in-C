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
