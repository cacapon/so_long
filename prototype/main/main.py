import pyxel


class App:
    def __init__(self):
        self.map = [
            ["1","1","1","1","1","1"],
            ["1","0","0","C","0","1"],
            ["1","P","0","0","E","1"],
            ["1","0","C","0","0","1"],
            ["1","1","1","1","1","1"],
        ]
        self.count = 0
        self.coin  = 2
        self.player = [2,1]
        self.is_clear = False
        pyxel.init(100, 100, title="So_Long ProtoType")
        pyxel.load("assets/my_resource.pyxres")
        pyxel.run(self.update, self.draw)

    def move(self, d_vec):
        p_mv = [self.player[0] + d_vec[0], self.player[1] + d_vec[1]]
        if self.map[p_mv[0]][p_mv[1]] == "1":
            return
        if self.map[p_mv[0]][p_mv[1]] == "C":
            self.coin -= 1
        if self.map[p_mv[0]][p_mv[1]] == "E":
            if self.coin == 0:
                self.is_clear = True
            else:
                return
        self.map[self.player[0]][self.player[1]] = "0"
        self.map[p_mv[0]][p_mv[1]] = "P"
        self.player = p_mv
        
    
    def update(self):
        if pyxel.btnp(pyxel.KEY_Q):
            pyxel.quit()
        if pyxel.btnp(pyxel.KEY_UP) or pyxel.btnp(pyxel.KEY_W):
            self.move([-1,0])
        if pyxel.btnp(pyxel.KEY_DOWN) or pyxel.btnp(pyxel.KEY_S):
            self.move([1,0])
        if pyxel.btnp(pyxel.KEY_LEFT) or pyxel.btnp(pyxel.KEY_A):
            self.move([0,-1])
        if pyxel.btnp(pyxel.KEY_RIGHT) or pyxel.btnp(pyxel.KEY_D):
            self.move([0,1])

    def draw(self):
        pyxel.cls(0)
        for y in range(len(self.map)):
            for x in range(len(self.map[0])):
                if self.map[y][x] == "0":
                    image = 0
                if self.map[y][x] == "P":
                    image = 8
                if self.map[y][x] == "C":
                    image = 16
                if self.map[y][x] == "1":
                    image = 24
                if self.map[y][x] == "E":
                    image = 32
                pyxel.blt(x*8, y*8, 0, image, 0, 8, 8)
        if self.is_clear:
            pyxel.text(4, 8*2, "GAME CLEAR!", pyxel.frame_count % 16)
                
App()
