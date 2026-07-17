# Pseudocode — Transformer Load and Efficiency Calculator System

```
BEGIN

    DISPLAY "TRANSFORMER LOAD AND EFFICIENCY CALCULATOR SYSTEM"

    // ---- Input and validate transformer details ----
    REPEAT
        INPUT transformerName
        INPUT transformerRatingKVA
        INPUT primaryVoltage
        INPUT secondaryVoltage
        INPUT powerFactor

        isValid = TRUE
        IF transformerRatingKVA <= 0 THEN
            DISPLAY "Error: rating must be greater than zero"
            isValid = FALSE
        IF primaryVoltage <= 0 OR secondaryVoltage <= 0 THEN
            DISPLAY "Error: voltages must be greater than zero"
            isValid = FALSE
        IF powerFactor <= 0 OR powerFactor > 1 THEN
            DISPLAY "Error: power factor must be between 0 and 1"
            isValid = FALSE

    UNTIL isValid = TRUE

    // ---- Input connected loads ----
    INPUT numberOfLoads
    WHILE numberOfLoads <= 0 DO
        DISPLAY "Invalid input, enter a positive whole number"
        INPUT numberOfLoads
    END WHILE

    totalLoadWatts = 0

    FOR i = 1 TO numberOfLoads DO
        INPUT loadName

        REPEAT
            INPUT powerRatingWatts
            IF powerRatingWatts < 0 THEN
                DISPLAY "Invalid input, value cannot be negative"
        UNTIL powerRatingWatts >= 0

        REPEAT
            INPUT quantity
            IF quantity < 0 THEN
                DISPLAY "Invalid input, value cannot be negative"
        UNTIL quantity >= 0

        loadPower = powerRatingWatts * quantity
        DISPLAY "Load Power: ", loadPower, " W"

        totalLoadWatts = totalLoadWatts + loadPower
    END FOR

    // ---- Calculations ----
    apparentLoadKVA   = totalLoadWatts / (powerFactor * 1000)
    loadingPercentage = (apparentLoadKVA / transformerRatingKVA) * 100

    // ---- Decision structure for load classification ----
    IF loadingPercentage < 40 THEN
        loadStatus = "Lightly Loaded"
    ELSE IF loadingPercentage <= 80 THEN
        loadStatus = "Normal Operating Range"
    ELSE IF loadingPercentage <= 100 THEN
        loadStatus = "Near Full Load"
    ELSE
        loadStatus = "Overloaded Transformer Warning"
    END IF

    // ---- Output ----
    DISPLAY "TRANSFORMER LOAD REPORT"
    DISPLAY transformerName, transformerRatingKVA, primaryVoltage,
            secondaryVoltage, powerFactor
    DISPLAY totalLoadWatts, apparentLoadKVA, loadingPercentage, loadStatus

    // ---- File saving process ----
    OPEN FILE "transformer_report.txt" FOR WRITING
    WRITE transformer details, load list, total load, apparent load,
          loading percentage, and load status TO FILE
    CLOSE FILE
    DISPLAY "Report saved to transformer_report.txt"

END
```
