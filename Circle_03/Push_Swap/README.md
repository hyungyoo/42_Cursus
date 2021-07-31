# push_swap
	1. stack_a, stack_b
	2. instruction : sa, sb, ra, rb, pa, pb, rra, rrb, ss, rr, rrr

# 구현 과정
	1. argv로 들어온 인자들을 구분
		동시에 인자들이 숫자 또는 ' '인지 확인, 아닐시 exit();
		"1 2 3" -> split으로 이중배열로 반환받아, 일반 노드로 변환
		1 2 3	-> 각각을 일반 노드로 전환
	
	2. 그렇게 받은 노드들을 더블 링크드 리스트로 받음
		동시에 duplicate 확인, duplicate일시 exit();
	
	3. Operation 구현
		pop 과 push 를 구현 한 후에, 모든 Operation 구현
	
	4. 알고리즘 
		stack 의 크기가 5이하인 경우에는 각각의 알고리즘을 바로 만들어준다
		
		ex)
		stack size == 0
			종료 (seg fault 일어날수 있음)
		stack size == 1
			종료 (seg fault 일어날수 있음)
		stack size == 2
			sa 또는 null
		stack size == 3
			최대값과 최소값을 이용하여 계산
		stack size == 4
			최대값 또는  최소값 이용 + stack size == 3 함수 이용
		stack size == 5
			최대값 그리고 최소값 이용 + stack size == 3 함수 이용


		stack size >=  6
			재귀함수과 정렬알고리즘 이용 + 2 pivot
		
	5. checker
		push_swap에서, 인자를 받아서 더블링크드리스트를 만든 과정을 그대로 복사 한 후에, 각 operation을 get_next_line함수로 받아서 실행.
		실행이 끝난 후에, ascending을 확인하는 함수로 정렬상태를 확인
	
	6. leaks!
		문제 없음!
	
	7. norminette
		문제 없음!
