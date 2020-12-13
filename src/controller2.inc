; Filename: controller2.inc
; Description: Game controller 2 file
; Author: David Brousseau

; Read controller 2 input
; A button
    LDA $4017
    AND #00000001
    CMP #1
    BNE b2
    LDA #1
    STA inUse

; B button
b2:
    LDA $4017
    AND #00000001
    CMP #1
    BNE select2
    LDA #2
    STA inUse

; Select button
select2:
    LDA $4017
    AND #00000001
    CMP #1
    BNE start2
    LDA #3
    STA inUse

; Start button
start2:
    LDA $4017
    AND #00000001
    CMP #1
    BNE upperPad2
    LDA #4
    STA inUse

; Upper direction pad button
upperPad2:
    LDA $4017
    AND #00000001
    CMP #1
    BNE lowerPad2
    JSR setUpperDirection

; Lower direction pad button
lowerPad2:
    LDA $4017
    AND #00000001
    CMP #1
    BNE leftPad2
    JSR setLowerDirection

; Left direction pad button
leftPad2:
    LDA $4017
    AND #00000001
    CMP #1
    BNE rightPad2
    JSR setLeftDirection

; Right direction pad button
rightPad2:
    LDA $4017
    AND #00000001
    CMP #1
    BNE endReadController2
    JSR setRightDirection
endReadController2:
    JMP endController2

; Possible directions of logos
; Set upper direction to the selected logo
setUpperDirection:
; Microsoft upper direction
    LDA inUse
    CMP #1
    BNE linuxUpper
    LDA #1
    STA microsoftDirection

; Linux upper direction
linuxUpper:
    LDA inUse
    CMP #2
    BNE appleUpper
    LDA #1
    STA linuxDirection

; Apple upper direction
appleUpper:
    LDA inUse
    CMP #3
    BNE cetiUpper
    LDA #1
    STA appleDirection

; Ceti upper direction
cetiUpper:
    LDA inUse
    CMP #4
    BNE endSetUpperDirection
    LDA #1
    STA cetiDirection
endSetUpperDirection:
    RTS

; Set lower direction to the selected logo
setLowerDirection:
; Microsoft lower direction
    LDA inUse
    CMP #1
    BNE linuxLower
    LDA #2
    STA microsoftDirection

; Linux lower direction
linuxLower:
    LDA inUse
    CMP #2
    BNE appleLower
    LDA #2
    STA linuxDirection

; Apple lower direction
appleLower:
    LDA inUse
    CMP #3
    BNE cetiLower
    LDA #2
    STA appleDirection

; Ceti lower direction
cetiLower:
    LDA inUse
    CMP #4
    BNE endSetLowerDirection
    LDA #2
    STA cetiDirection
endSetLowerDirection:
    RTS

; Set left direction to the selected logo
setLeftDirection:
; Microsoft left direction
    LDA inUse
    CMP #1
    BNE linuxLeft
    LDA #3
    STA microsoftDirection

; Linux left direction
linuxLeft:
    LDA inUse
    CMP #2
    BNE appleLeft
    LDA #3
    STA linuxDirection

; Apple left direction
appleLeft:
    LDA inUse
    CMP #3
    BNE cetiLeft
    LDA #3
    STA appleDirection

; Ceti left direction
cetiLeft:
    LDA inUse
    CMP #4
    BNE endSetLeftDirection
    LDA #3
    STA cetiDirection
endSetLeftDirection:
    RTS

; Set right direction to the selected logo
setRightDirection:
; Microsoft right direction
    LDA inUse
    CMP #1
    BNE linuxRight
    LDA #4
    STA microsoftDirection

; Linux right direction
linuxRight:
    LDA inUse
    CMP #2
    BNE appleRight
    LDA #4
    STA linuxDirection

; Apple right direction
appleRight:
    LDA inUse
    CMP #3
    BNE cetiRight
    LDA #4
    STA appleDirection

; Ceti right direction
cetiRight:
    LDA inUse
    CMP #4
    BNE endSetRightDirection
    LDA #4
    STA cetiDirection
endSetRightDirection:
    RTS

endController2:
