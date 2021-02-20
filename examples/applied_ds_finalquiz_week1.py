import re
def result():
    s = 'ACAABAACAAABACDBADDDFSDDDFFSSSASDAFAAACBAAAFASD'

    result = []
    # compete the pattern below
    pattern = re.compile(r'[^A](?=AAA)')
    for item in re.finditer(pattern, s):
      # identify the group number below.
      result.append(item.group())
    
    return result

print(result())