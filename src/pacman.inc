; Filename: pacman.inc
; Description: Pac-Man's logo shifting file
; Author: David Brousseau

    JSR setCounter
    JSR setPacmanAnimation
    JSR setPacmanTowardTo
    JMP endPacmanShifting

; Set the NMI counter
setCounter:
    LDA counter
    CMP #20 ; Reset after 20 turns
    BNE endSetCounter
    JSR setMouth
    LDA #0
    STA counter

endSetCounter:
    RTS

; Set Pac-Man's mouth
setMouth:
; Open mouth
    LDA mouth
    CMP #1
    BNE closeMouth
    LDA #0
    STA mouth
    JMP endSetMouth

closeMouth:
    LDA #1
    STA mouth
    JMP endSetMouth

endSetMouth:
    RTS

; Set Pac-Man's sprite animation
setPacmanAnimation:
    LDA mouth
    CMP #1
    BNE pacmanFaceUp
    JSR drawPacmanMouthClose
    JMP endPacmanAnimation

pacmanFaceUp:
    LDA direction
    CMP #1
    BNE pacmanFaceDown
    JSR drawPacmanFaceUp
    JMP endPacmanAnimation

pacmanFaceDown:
    LDA direction
    CMP #2
    BNE pacmanFaceLeft
    JSR drawPacmanFaceDown
    JMP endPacmanAnimation

pacmanFaceLeft:
    LDA direction
    CMP #3
    BNE pacmanFaceRight
    JSR drawPacmanFaceLeft
    JMP endPacmanAnimation

pacmanFaceRight:
    LDA direction
    CMP #4
    BNE endPacmanAnimation
    JSR drawPacmanFaceRight

endPacmanAnimation:
    RTS

drawPacmanMouthClose:
    LDA #2
    STA $201
    LDA #%10000001
    STA $202
    LDA #2
    STA $205
    LDA #%11000001
    STA $206
    LDA #2
    STA $209
    LDA #%00000001
    STA $20A
    LDA #2
    STA $20D
    LDA #%01000001
    STA $20E
    RTS

drawPacmanFaceUp:
    LDA #1
    STA $201
    LDA #%00000001
    STA $202
    LDA #1
    STA $205
    LDA #%01000001
    STA $206
    LDA #2
    STA $209
    LDA #%00000001
    STA $20A
    LDA #2
    STA $20D
    LDA #%01000001
    STA $20E
    RTS

drawPacmanFaceDown:
    LDA #2
    STA $201
    LDA #%10000001
    STA $202	
    LDA #2
    STA $205
    LDA #%11000001
    STA $206
    LDA #1
    STA $209
    LDA #%10000001
    STA $20A
    LDA #1
    STA $20D
    LDA #%11000001
    STA $20E
    RTS

drawPacmanFaceLeft:
    LDA #0
    STA $201
    LDA #%01000001
    STA $202
    LDA #2
    STA $205
    LDA #%11000001
    STA $206
    LDA #0
    STA $209
    LDA #%11000001
    STA $20A
    LDA #2
    STA $20D
    LDA #%01000001
    STA $20E
    RTS

drawPacmanFaceRight:
    LDA #2
    STA $201
    LDA #%10000001
    STA $202
    LDA #0
    STA $205
    LDA #%00000001
    STA $206
    LDA #2
    STA $209
    LDA #%00000001
    STA $20A
    LDA #0
    STA $20D
    LDA #%10000001
    STA $20E
    RTS

; Set Pac-Man's logo direction toward to
setPacmanTowardTo:
; Pac-Man toward up
    LDA direction
    CMP #1
    BNE pacmanTowardDown
    JSR shiftPacmanUp
    JMP endPacmanTowardTo

pacmanTowardDown:
    LDA direction
    CMP #2
    BNE pacmanTowardLeft
    JSR shiftPacmanDown
    JMP endPacmanTowardTo

pacmanTowardLeft:
    LDA direction
    CMP #3
    BNE pacmanTowardRight
    JSR shiftPacmanLeft
    JMP endPacmanTowardTo

pacmanTowardRight:
    LDA direction
    CMP #4
    BNE endPacmanTowardTo
    JSR shiftPacmanRight

endPacmanTowardTo:
    RTS

; Apply shifting toward up to Pac-Man's logo
shiftPacmanUp:
    LDA $200
    SEC
    SBC #1
    STA $200
    LDA $204
    SEC
    SBC #1
    STA $204
    LDA $208
    SEC
    SBC #1
    STA $208
    LDA $20C
    SEC
    SBC #1
    STA $20C
    RTS

; Apply shifting toward down to Pac-Man's logo
shiftPacmanDown:
    LDA $200
    CLC
    ADC #1
    STA $200
    LDA $204
    CLC
    ADC #1
    STA $204
    LDA $208
    CLC
    ADC #1
    STA $208
    LDA $20C
    CLC
    ADC #1
    STA $20C
    RTS

; Apply shifting toward left to Pac-Man's logo
shiftPacmanLeft:
    LDA $203
    SEC
    SBC #1
    STA $203
    LDA $207
    SEC
    SBC #1
    STA $207
    LDA $20B
    SEC
    SBC #1
    STA $20B
    LDA $20F
    SEC
    SBC #1
    STA $20F
    RTS

; Apply shifting toward right to Pac-Man's logo
shiftPacmanRight:
    LDA $203
    CLC
    ADC #1
    STA $203
    LDA $207
    CLC
    ADC #1
    STA $207
    LDA $20B
    CLC
    ADC #1
    STA $20B
    LDA $20F
    CLC
    ADC #1
    STA $20F
    RTS

endPacmanShifting:
