def solution(participant, completion):
    answer = ''
    hash_dic = {}
    hash_tot = 0
    
    #참가자
    for part in participant:
        hash_dic[hash(part)] = part
        hash_tot += hash(part)
    
    #완주자들로 tot에서 빼기
    for com in completion:
        hash_tot -= hash(com)
    
    #답교체
    answer = hash_dic[hash_tot]
    
    #반환
    return answer