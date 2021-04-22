# 프로그래머스: 신규 아이디 추천
import re

def step1(id):
    return id.lower()
def step2(id):
    return re.sub(r'[^a-z0-9-_.]', '', id)
def step3(id):
    return re.sub(r'[.]{2,}', '.', id)
def step4(id): # re.sub('^[.]|[.]$', '', id) 한줄로 가능
    s = re.sub(r'^\.', '', id)
    return re.sub(r'\.$', '', s)
def step5(id):
    if len(id) == 0:
        return 'a'
    return id
def step6(id):
    if len(id) >= 16:
        return step4(id[:15]) 
    return id
def step7(id):
    if len(id) <= 2:
        return id + id[-1] * (3 - len(id))
    return id
def solution(new_id):
    return step7(step6(step5(step4(step3(step2(step1(new_id)))))))

print(solution("...!@BaT#*..y.abcdefghijklm"))

