import pandas as pd

# a
products = pd.read_csv('products.csv')
orders = pd.read_csv('orders.csv')

# b
print(products.head(), products.tail(10), '', sep='\n\n')
print(orders.head(), orders.tail(10), sep ='\n\n')

# c
merged = pd.merge(products, orders, how="inner", on="ProductID")
merged['Revenue'] = (merged['Quantity'] * merged['Price'])
print("\nTotal Revenue :", merged['Revenue'].sum())

# d
top5BestSelling = merged.nlargest(5, 'Revenue')
print("TOP 5 BEST SELLING PRODUCTS")
print(top5BestSelling)

top5LowSelling = merged.nsmallest(5, 'Revenue')
print("\nTOP 5 LOW SELLING PRODUCTS")
print(top5LowSelling)

# e
print("\nTop 5 best selling most common product category :", top5BestSelling['Category'].mode()[0])

# f
print("\nAverage price of products in each category :\n")
print(products.groupby('Category')['Price'].mean())

# g
merged['Order Date'] = pd.to_datetime(merged['Order Date'])
highestRevenue = merged.loc[merged['Revenue'].idxmax()]
print(f"\nDay of highest revenue : {highestRevenue['Order Date'].day}\nMonth of highest revenue : {highestRevenue['Order Date'].month}\nYear of highest revenue : {highestRevenue['Order Date'].year}")

# h
merged['Month'] = merged['Order Date'].dt.month
merged['Year'] = merged['Order Date'].dt.year
mothlyRevenue = merged.groupby(['Year', 'Month'])['Revenue'].sum().reset_index()
print()
print(mothlyRevenue)

# i
print()
print(merged.dropna())