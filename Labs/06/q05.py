import pandas as pd   

data = {
    'year': [1988, 1986, 1985],
    'WHO region': ['Western Pecific', 'Americans', 'Africa'],
    'Country': ['Veit Nam', 'Uruguay', "Cle d'Ivoire"],
    'Beverage types': ['Wine', 'Other', 'Wine'],
    'Display Value': [0, 0.5, 1.62]
}

df = pd.DataFrame(data)
print(df.shape)

print(df.columns)
