score = 70
grade = ""

if(score >= 90) {
    grade = "A"
} else if(score >= 80) {
    grade = "B"
} else if(score >= 70) {
    grade = "C"
} else {
    grade = "Fail"
}

print(paste("Grade :", grade))
