import re

text = '''As we move forward with our project, please make sure to coordinate with the relevant team members: for marketing insights, reach out to Sarah at sarah.marketing@example.com, and if you have any budget questions, John is available at john.budget@example.com. For technical assistance, Mike can be contacted at mike.tech@example.com, while logistics inquiries should be directed to Emily at emily.logistics@example.com. Lastly, for HR matters, feel free to email Lisa at lisa.hr@example.com.'''
pattern = r"\b([a-z0-9._%+-]+@[a-z0-9.-]+.[a-z]{3,})\b"

emails = re.findall(pattern, text)

print(emails)
