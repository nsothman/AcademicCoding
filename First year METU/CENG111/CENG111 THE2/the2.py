def BlockArea(Block1, Block2):
    FirstArea = (Block1[0] - Block1[2]) * (Block1[1] - Block1[3])
    SecArea = (Block2[0] - Block2[2]) * (Block2[1] - Block2[3])
    Area = FirstArea + SecArea
    XOverlap = min(Block1[0], Block2[0]) - max(Block1[2], Block2[2])
    YOverlap = min(Block1[1], Block2[1]) - max(Block1[3], Block2[3])
    if XOverlap > 0 and YOverlap > 0:
        OverlapArea = XOverlap * YOverlap
        if OverlapArea == FirstArea:
            Area = SecArea
        elif OverlapArea == SecArea:
            Area = FirstArea
        elif OverlapArea > 0:
            Area = Area - OverlapArea
    return float(Area)

def is_firmus(FirstBlock, SecBlock):

    if abs(SecBlock[1] + SecBlock[3]) < abs(FirstBlock[1] + FirstBlock[3]):
        LowerBlock = [max(SecBlock[0], SecBlock[2]), max(SecBlock[1], SecBlock[3]), min(SecBlock[0], SecBlock[2]), min(SecBlock[1], SecBlock[3])]
        UpperBlock = [max(FirstBlock[0], FirstBlock[2]), max(FirstBlock[1], FirstBlock[3]), min(FirstBlock[0], FirstBlock[2]), min(FirstBlock[1], FirstBlock[3])]
    else:
        LowerBlock = [max(FirstBlock[0], FirstBlock[2]), max(FirstBlock[1], FirstBlock[3]), min(FirstBlock[0], FirstBlock[2]), min(FirstBlock[1], FirstBlock[3])]
        UpperBlock = [max(SecBlock[0], SecBlock[2]), max(SecBlock[1], SecBlock[3]), min(SecBlock[0], SecBlock[2]), min(SecBlock[1], SecBlock[3])]

    if abs(LowerBlock[3]) < 0.001:

        if abs(LowerBlock[1] - UpperBlock[3]) < 0.001 and (UpperBlock[2] < LowerBlock[0] or abs(UpperBlock[2] - LowerBlock[0]) < 0.001):

            Abscissa = (UpperBlock[2] + UpperBlock[0]) / 2.0

            if (abs(Abscissa - LowerBlock[2]) < 0.001 or Abscissa > LowerBlock[2]) and (abs(Abscissa - LowerBlock[0]) < 0.001 or Abscissa < LowerBlock[0]):
                return ["FIRMUS", BlockArea(LowerBlock, UpperBlock)]

            else:
                if Abscissa < LowerBlock[2]:
                    Extra = UpperBlock[0] + (2 * abs(Abscissa - LowerBlock[2]))
                    return ["ADDENDUM", [UpperBlock[0],  UpperBlock[3], Extra, UpperBlock[1]]]
                else:
                    Extra = UpperBlock[2] - (2 * abs(Abscissa - LowerBlock[0]))
                    return ["ADDENDUM", [UpperBlock[2], UpperBlock[3], Extra, UpperBlock[1]]]
        else:
            return ["DAMNARE", BlockArea(LowerBlock, UpperBlock)]
    else:
        return ["DAMNARE", BlockArea(LowerBlock, UpperBlock)]
