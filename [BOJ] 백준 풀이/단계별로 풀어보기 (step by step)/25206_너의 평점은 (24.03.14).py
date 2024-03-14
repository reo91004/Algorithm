import sys

input = sys.stdin.readline

if __name__ == "__main__":
    # 성적 기준
    rating = {
        "A+": 4.5,
        "A0": 4.0,
        "B+": 3.5,
        "B0": 3.0,
        "C+": 2.5,
        "C0": 2.0,
        "D+": 1.5,
        "D0": 1.0,
        "F": 0.0,
    }

    scoreSum, res = 0, 0

    for _ in range(20):
        subject, score, grade = input().rstrip().split()
        score = float(score)
        if grade == "P":
            continue

        # 학점 공식
        res += score * rating[grade]
        scoreSum += score

    print(res / scoreSum)
