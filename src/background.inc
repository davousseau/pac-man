; Filename: background.inc
; Description: Game background file
; Author: David Brousseau

; Bank initialization
    .bank 2
    .org $0000 ; Writing starts at $0000

; Draw background tile
    .db %00001111
    .db %00001111
    .db %00001111
    .db %00001111
    .db %11110000
    .db %11110000
    .db %11110000
    .db %11110000
