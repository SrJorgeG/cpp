# Exercise 00: Bitcoin Exchange

## What it does

Reads a file with `date | value` lines and looks up the Bitcoin exchange rate for each date from a CSV database (`data.csv`). Outputs the multiplied value, or an error message for invalid input.

## Key concepts

- **std::map**: The core container used for the exchange rate database. `std::map` stores key-value pairs in sorted order by key, making date-based lookups efficient.
- **`lower_bound()`**: Used to find the closest lower date when an exact date match isn't found. This is the killer feature of `std::map` for this exercise — logarithmic-time range queries on ordered keys.
- **CSV parsing**: Reading comma-separated and pipe-separated data with `std::getline` and `std::istringstream`.
- **Input validation**: Date format validation (YYYY-MM-DD), value range checking (0–1000), and handling malformed lines.

## How the implementation works

1. `loadDatabase()` reads `data.csv` line by line, parsing each `date,exchange_rate` pair into the `std::map<std::string, float>`.
2. `processInput()` reads the user's input file, validates each line, and performs the lookup.
3. For the date lookup, `lower_bound(date)` returns an iterator to the first entry >= the requested date. If it's an exact match, use it. Otherwise, decrement the iterator to get the closest lower date.
4. Error messages follow the subject specification exactly.

## Container choice

**std::map** was chosen because:
- Keys (dates as strings) are naturally ordered, and `std::map` maintains this ordering.
- `lower_bound()` provides O(log n) lookup for the closest date — exactly what the exercise needs.
- The sorted nature of `std::map` means we never need to sort the data ourselves.
