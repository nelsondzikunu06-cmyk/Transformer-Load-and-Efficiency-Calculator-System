# Test Data — Transformer Load and Efficiency Calculator System

This document records the test cases used to verify that the programme
calculates and classifies transformer loading correctly, and that it
correctly rejects invalid input.

## Test Case 1 — Normal Operating Range (Specification Example)

| Input | Value |
|---|---|
| Transformer Name | Lab Transformer 1|
| Transformer Rating | 10 kVA |
| Primary Voltage | 11000 V |
| Secondary Voltage | 415 V |
| Power Factor | 0.85 |
| Number of Load Types | 3 |
| Load 1 | Lighting Circuit, 60 W, Qty 20 |
| Load 2 | Socket Outlet Load, 500 W, Qty 4 |
| Load 3 | Motor Load, 1500 W, Qty 2 |

**Expected Result:**
- Total Connected Load = 6200 W
- Apparent Load = 7.29 kVA
- Loading Percentage = 72.94 %
- Load Status = **Normal Operating Range**

**Actual Result:** Matched expected result. ✅

## Test Case 2 — Lightly Loaded Transformer

| Input | Value |
|---|---|
| Transformer Name | Store Room Transformer |
| Transformer Rating | 25 kVA |
| Primary Voltage | 11000 V |
| Secondary Voltage | 415 V |
| Power Factor | 0.9 |
| Number of Load Types | 1 |
| Load 1 | Small Motor, 2000 W, Qty 1 |

**Expected Result:**
- Total Connected Load = 2000 W
- Apparent Load = 2.22 kVA
- Loading Percentage = 8.89 %
- Load Status = **Lightly Loaded** (below 40%)

**Actual Result:** Matched expected result. ✅

## Test Case 3 — Near Full Load Transformer

| Input | Value |
|---|---|
| Transformer Name | Workshop Transformer |
| Transformer Rating | 5 kVA |
| Primary Voltage | 11000 V |
| Secondary Voltage | 415 V |
| Power Factor | 0.8 |
| Number of Load Types | 2 |
| Load 1 | Welding Machine, 3000 W, Qty 1 |
| Load 2 | Lighting, 100 W, Qty 10 |

**Expected Result:**
- Total Connected Load = 4000 W
- Apparent Load = 5.00 kVA
- Loading Percentage = 100.00 %
- Load Status = **Near Full Load** (81–100%)

**Actual Result:** Matched expected result. ✅

## Test Case 4 — Overloaded Transformer

| Input | Value |
|---|---|
| Transformer Name | Old Feeder Transformer |
| Transformer Rating | 5 kVA |
| Primary Voltage | 11000 V |
| Secondary Voltage | 415 V |
| Power Factor | 0.8 |
| Number of Load Types | 1 |
| Load 1 | Industrial Heater, 6000 W, Qty 1 |

**Expected Result:**
- Total Connected Load = 6000 W
- Apparent Load = 7.50 kVA
- Loading Percentage = 150.00 %
- Load Status = **Overloaded Transformer Warning** (above 100%)

**Actual Result:** Matched expected result. ✅

## Test Case 5 — Input Validation (Negative and Non-Numeric Values)

| Action | Expected Programme Behaviour |
|---|---|
| Enter a negative transformer rating (e.g. `-10`) | Programme displays an error and asks for the transformer details again |
| Enter a power factor greater than 1 (e.g. `1.5`) | Programme displays "power factor must be between 0 and 1" and re-prompts |
| Enter letters instead of a number (e.g. `abc` for power rating) | Programme clears the invalid input and re-prompts without crashing |
| Enter a negative quantity for a load (e.g. `-5`) | Programme rejects the value and re-prompts for quantity |
| Enter `0` for number of load types | Programme rejects the value and re-prompts for a positive whole number |

**Actual Result:** All invalid entries were correctly rejected and the
programme continued to prompt for valid input without crashing or
terminating unexpectedly. ✅

## Summary

| Test Case | Status |
|---|---|
| 1 — Normal Operating Range | Passed |
| 2 — Lightly Loaded | Passed |
| 3 — Near Full Load | Passed |
| 4 — Overloaded Transformer | Passed |
| 5 — Input Validation | Passed |

All test cases produced the expected results, confirming that the
calculations, classification logic, and input validation work as intended.
