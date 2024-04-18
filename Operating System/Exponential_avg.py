def exponetial_avg(recent_info, alpha):
    
    tau = [0 for i in range(len(recent_info) + 1)]
    tau[0] = recent_info[0]
    
    for i in range(len(tau)-1):
        tau[i+1] = alpha * recent_info[i] + (1 - alpha) * tau[i]
    return tau[-1]

if __name__ == '__main__':
    recent_info = [19.5, 18.4, 17.8, 18.1, 20.6, 24, 23.5, 21.2, 22.3, 21.2]
    
    alpha = [0.3, 0.5, 0.7, 0.9]
    print('최근 정보:')
    print('5월 11~20일까지의 하루 평균 기온')
    print(recent_info)
    print()
    for i in alpha:
        print('alpha = ', i)
        print('예측값' ,exponetial_avg(recent_info, i))
        print()