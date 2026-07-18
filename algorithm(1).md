# Algorithm — Transformer Load and Efficiency Calculator System

This document presents the step-by-step algorithm followed by the C++ programme
in `main.cpp`.

## Algorithm

1. **Start.**
2. Display the project title / welcome banner.
3. **Repeat** the following until the transformer details are valid:
   1. Prompt the user to enter: transformer name, transformer rating (kVA),
      primary voltage, secondary voltage, and power factor.
   2. Validate the entered details:
      - Transformer rating must be greater than zero.
      - Primary voltage and secondary voltage must be greater than zero.
      - Power factor must be greater than zero and not greater than 1.
   3. If any value is invalid, display an error message and return to step 3.1.
4. Prompt the user to enter the number of connected load types, `n`
   (must be a whole number greater than zero).
5. Initialise `TotalLoad = 0`.
6. **For** `i = 1` to `n`, **repeat**:
   1. Prompt the user to enter the load name, power rating (watts), and quantity
      for load type `i`.
   2. Validate that the power rating and quantity are not negative. If invalid,
      re-prompt for that value.
   3. Calculate: `LoadPower = PowerRating x Quantity`.
   4. Display the calculated load power for that load type.
   5. Add `LoadPower` to `TotalLoad`.
7. Calculate the apparent load:
   `ApparentLoad (kVA) = TotalLoad / (PowerFactor x 1000)`.
8. Calculate the transformer loading percentage:
   `LoadingPercentage = (ApparentLoad / TransformerRating) x 100`.
9. Determine the load status using the following decision rule:
   - If `LoadingPercentage < 40` → **Lightly Loaded**.
   - Else if `LoadingPercentage <= 80` → **Normal Operating Range**.
   - Else if `LoadingPercentage <= 100` → **Near Full Load**.
   - Else → **Overloaded Transformer Warning**.
10. Display the full transformer load report on the screen, showing the
    transformer details, total load, apparent load, loading percentage, and
    load status.
11. Save the same report to a text file named `transformer_report.txt`.
12. Display a confirmation message that the report has been saved.
13. **Stop.**


## Notes on Design Decisions

- Validation is placed **inside a loop** (step 3) rather than a single check so
  that the user is asked to re-enter details as many times as necessary instead
  of the programme terminating on the first mistake.
- The load-type loop (step 6) uses a `for` loop because the number of
  iterations (`n`) is known in advance, once entered by the user.
- Individual load validation (step 6.2) is handled with its own `while` loop
  inside the input function so a single bad value doesn't force the user to
  re-enter the whole load record.
