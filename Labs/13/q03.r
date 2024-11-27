given_year = 1900
is_leap = FALSE

if(!(given_year %% 400)) {
    is_leap = TRUE
} else if(!(given_year %% 4) && given_year %% 100) {
    is_leap = TRUE
}

if(is_leap) {
    print(paste(given_year, "is leap year"))
} else {
    print(paste(given_year, "is not a leap year"))
}
