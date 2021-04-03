# Matching Residents to Hospitals (婚姻匹配问题)
__Goal__: Given a set of preferences among hospitals and medical school students, design a __self-reinfocing__ admissions process.(根据毕业生和医院间的偏好顺序，给出自强化的偏好方案)

__Unstable pair__:(不稳定对) applicant x and hospital y are __unstable__ if:
- x prefers y to its assigned hospital.
- y prefers x to one of its admitted students.

__Stable assignment__: Assignment with no unstable pairs.

