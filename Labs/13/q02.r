list1 = list(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
sum = 0

for(num in list1) {
    if((!num %% 2)) {
        sum = sum + num
    }
}

print(paste("Sum of even numbers :", sum))
