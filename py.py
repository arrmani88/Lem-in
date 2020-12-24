import re
s = "Fract'ol    3000 3475"
lst = re.split('\ +', s)
print(lst)