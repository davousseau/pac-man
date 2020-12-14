; Filename: ceti.inc
; Description: Céti's logo shifting file
; Author: David Brousseau

    JSR setCetiTowardTo
    JMP endCetiShifting

; Set Céti's logo direction toward to
setCetiTowardTo:
; Céti toward up
    LDA cetiDirection
    CMP #1
    BNE cetiTowardDown
    JSR shiftCetiUp
    JMP endCetiTowardTo

cetiTowardDown:
    LDA cetiDirection
    CMP #2
    BNE cetiTowardLeft
    JSR shiftCetiDown
    JMP endCetiTowardTo

cetiTowardLeft:
    LDA cetiDirection
    CMP #3
    BNE cetiTowardRight
    JSR shiftCetiLeft
    JMP endCetiTowardTo

cetiTowardRight:
    LDA cetiDirection
    CMP #4
    BNE endCetiTowardTo
    JSR shiftCetiRight
endCetiTowardTo:
    RTS

; Apply shifting toward up to Céti's logo
shiftCetiUp:
    LDA $240
    SEC
    SBC #1
    STA $240
    LDA $244
    SEC
    SBC #1
    STA $244
    LDA $248
    SEC
    SBC #1
    STA $248
    LDA $24C
    SEC
    SBC #1
    STA $24C
    RTS

; Apply shifting toward down to Céti's logo
shiftCetiDown:
    LDA $240
    CLC
    ADC #1
    STA $240
    LDA $244
    CLC
    ADC #1
    STA $244
    LDA $248
    CLC
    ADC #1
    STA $248
    LDA $24C
    CLC
    ADC #1
    STA $24C
    RTS

; Apply shifting toward left to Céti's logo
shiftCetiLeft:
    LDA $243
    SEC
    SBC #1
    STA $243
    LDA $247
    SEC
    SBC #1
    STA $247
    LDA $24B
    SEC
    SBC #1
    STA $24B
    LDA $24F
    SEC
    SBC #1
    STA $24F
    RTS

; Apply shifting toward right to Céti's logo
shiftCetiRight:
    LDA $243
    CLC
    ADC #1
    STA $243
    LDA $247
    CLC
    ADC #1
    STA $247
    LDA $24B
    CLC
    ADC #1
    STA $24B
    LDA $24F
    CLC
    ADC #1
    STA $24F
    RTS

endCetiShifting:
