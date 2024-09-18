import re

text = '''The project timeline includes several important dates: the kickoff meeting is scheduled for 12/09/2023, followed by the phase one deadline on 2023-09-15. We will have a review meeting on Sep 12, 2023, and the final submission is due on 2023-10-01. Lastly, feedback is due by 10/10/2023. Please mark these dates on your calendar.'''
pattern = r"\b(\d{1,2}/\d{1,2}/\d{4}|\d{4}-\d{1,2}-\d{1,2}|[A-Za-z]{3,} \d{1,2}, \d{4})\b"

dates = re.findall(pattern, text)
print(dates)
