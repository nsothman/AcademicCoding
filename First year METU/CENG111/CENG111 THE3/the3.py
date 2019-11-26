
from evaluator import *
import math

InputList = get_data()

def new_move():
	"""Function that calculates the position updates.
       * Returns [[Delta_x1, Delta_y2], ..., [Delta_xm, Delta_ym]]"""

	Output = []
	v = []

	for i in range(2, len(InputList)):
		a = [0., 0.]
		v.append([InputList[i][3], InputList[i][4]])
		for j in range(2, len(InputList)):
			dr = [(InputList[j][1] + v[i - 2][0] * InputList[1]) - (InputList[i][1] + v[i - 2][0] * InputList[1]), (InputList[j][2] + v[i - 2][1] * InputList[1]) - (InputList[i][2] + v[i - 2][1] * InputList[1])]
			if i == j or (abs(dr[0]) <= 0.001 and abs(dr[1]) <= 0.001):
				continue
			AbsR = math.sqrt((dr[0] ** 2) + (dr[1] ** 2))
			a = [((dr[0] * InputList[j][0] * InputList[0]) / AbsR ** 3) + a[0], ((dr[1] * InputList[j][0] * InputList[0]) / AbsR ** 3) + a[1]]
		v[i - 2] = [a[0] * InputList[1] + v[i - 2][0], a[1] * InputList[1] + v[i - 2][1]]
		Output.append([v[i - 2][0] * InputList[1], v[i - 2][1] * InputList[1]])

	for i in range(2, len(InputList)):
		InputList[i] = [InputList[i][0], InputList[i][1] + Output[i - 2][0], InputList[i][2] + Output[i - 2][1], v[i - 2][0], v[i - 2][1]]

	return Output
