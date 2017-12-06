#!/bin/sh
# the next line restarts using wish\
exec wish "$0" "$@" 

if {![info exists vTcl(sourcing)]} {

    package require Tk
    switch $tcl_platform(platform) {
	windows {
            option add *Button.padY 0
	}
	default {
            option add *Scrollbar.width 10
            option add *Scrollbar.highlightThickness 0
            option add *Scrollbar.elementBorderWidth 2
            option add *Scrollbar.borderWidth 2
	}
    }
    
}

#############################################################################
# Visual Tcl v1.60 Project
#




#############################################################################
## vTcl Code to Load Stock Images


if {![info exist vTcl(sourcing)]} {
#############################################################################
## Procedure:  vTcl:rename

proc ::vTcl:rename {name} {
    ## This procedure may be used free of restrictions.
    ##    Exception added by Christian Gavin on 08/08/02.
    ## Other packages and widget toolkits have different licensing requirements.
    ##    Please read their license agreements for details.

    regsub -all "\\." $name "_" ret
    regsub -all "\\-" $ret "_" ret
    regsub -all " " $ret "_" ret
    regsub -all "/" $ret "__" ret
    regsub -all "::" $ret "__" ret

    return [string tolower $ret]
}

#############################################################################
## Procedure:  vTcl:image:create_new_image

proc ::vTcl:image:create_new_image {filename {description {no description}} {type {}} {data {}}} {
    ## This procedure may be used free of restrictions.
    ##    Exception added by Christian Gavin on 08/08/02.
    ## Other packages and widget toolkits have different licensing requirements.
    ##    Please read their license agreements for details.

    # Does the image already exist?
    if {[info exists ::vTcl(images,files)]} {
        if {[lsearch -exact $::vTcl(images,files) $filename] > -1} { return }
    }

    if {![info exists ::vTcl(sourcing)] && [string length $data] > 0} {
        set object [image create  [vTcl:image:get_creation_type $filename]  -data $data]
    } else {
        # Wait a minute... Does the file actually exist?
        if {! [file exists $filename] } {
            # Try current directory
            set script [file dirname [info script]]
            set filename [file join $script [file tail $filename] ]
        }

        if {![file exists $filename]} {
            set description "file not found!"
            ## will add 'broken image' again when img is fixed, for now create empty
            set object [image create photo -width 1 -height 1]
        } else {
            set object [image create  [vTcl:image:get_creation_type $filename]  -file $filename]
        }
    }

    set reference [vTcl:rename $filename]
    set ::vTcl(images,$reference,image)       $object
    set ::vTcl(images,$reference,description) $description
    set ::vTcl(images,$reference,type)        $type
    set ::vTcl(images,filename,$object)       $filename

    lappend ::vTcl(images,files) $filename
    lappend ::vTcl(images,$type) $object

    # return image name in case caller might want it
    return $object
}

#############################################################################
## Procedure:  vTcl:image:get_image

proc ::vTcl:image:get_image {filename} {
    ## This procedure may be used free of restrictions.
    ##    Exception added by Christian Gavin on 08/08/02.
    ## Other packages and widget toolkits have different licensing requirements.
    ##    Please read their license agreements for details.

    set reference [vTcl:rename $filename]

    # Let's do some checking first
    if {![info exists ::vTcl(images,$reference,image)]} {
        # Well, the path may be wrong; in that case check
        # only the filename instead, without the path.

        set imageTail [file tail $filename]

        foreach oneFile $::vTcl(images,files) {
            if {[file tail $oneFile] == $imageTail} {
                set reference [vTcl:rename $oneFile]
                break
            }
        }
    }
    return $::vTcl(images,$reference,image)
}

#############################################################################
## Procedure:  vTcl:image:get_creation_type

proc ::vTcl:image:get_creation_type {filename} {
    ## This procedure may be used free of restrictions.
    ##    Exception added by Christian Gavin on 08/08/02.
    ## Other packages and widget toolkits have different licensing requirements.
    ##    Please read their license agreements for details.

    switch [string tolower [file extension $filename]] {
        .ppm -
        .jpg -
        .bmp -
        .gif    {return photo}
        .xbm    {return bitmap}
        default {return photo}
    }
}

foreach img {


            } {
    eval set _file [lindex $img 0]
    vTcl:image:create_new_image\
        $_file [lindex $img 1] [lindex $img 2] [lindex $img 3]
}

}
#############################################################################
## vTcl Code to Load User Images

catch {package require Img}

foreach img {

        {{[file join / home hfs livrusvirtus tcl LivrusVirtus.gif]} {user image} user {}}
        {{[file join / home hfs livrusvirtus tcl Livro.gif]} {user image} user {}}
        {{[file join / home hfs livrusvirtus tcl cliente.gif]} {user image} user {}}

            } {
    eval set _file [lindex $img 0]
    vTcl:image:create_new_image\
        $_file [lindex $img 1] [lindex $img 2] [lindex $img 3]
}

#################################
# VTCL LIBRARY PROCEDURES
#

if {![info exists vTcl(sourcing)]} {
#############################################################################
## Library Procedure:  Window

proc ::Window {args} {
    ## This procedure may be used free of restrictions.
    ##    Exception added by Christian Gavin on 08/08/02.
    ## Other packages and widget toolkits have different licensing requirements.
    ##    Please read their license agreements for details.

    global vTcl
    foreach {cmd name newname} [lrange $args 0 2] {}
    set rest    [lrange $args 3 end]
    if {$name == "" || $cmd == ""} { return }
    if {$newname == ""} { set newname $name }
    if {$name == "."} { wm withdraw $name; return }
    set exists [winfo exists $newname]
    switch $cmd {
        show {
            if {$exists} {
                wm deiconify $newname
            } elseif {[info procs vTclWindow$name] != ""} {
                eval "vTclWindow$name $newname $rest"
            }
            if {[winfo exists $newname] && [wm state $newname] == "normal"} {
                vTcl:FireEvent $newname <<Show>>
            }
        }
        hide    {
            if {$exists} {
                wm withdraw $newname
                vTcl:FireEvent $newname <<Hide>>
                return}
        }
        iconify { if $exists {wm iconify $newname; return} }
        destroy { if $exists {destroy $newname; return} }
    }
}
#############################################################################
## Library Procedure:  vTcl:DefineAlias

proc ::vTcl:DefineAlias {target alias widgetProc top_or_alias cmdalias} {
    ## This procedure may be used free of restrictions.
    ##    Exception added by Christian Gavin on 08/08/02.
    ## Other packages and widget toolkits have different licensing requirements.
    ##    Please read their license agreements for details.

    global widget
    set widget($alias) $target
    set widget(rev,$target) $alias
    if {$cmdalias} {
        interp alias {} $alias {} $widgetProc $target
    }
    if {$top_or_alias != ""} {
        set widget($top_or_alias,$alias) $target
        if {$cmdalias} {
            interp alias {} $top_or_alias.$alias {} $widgetProc $target
        }
    }
}
#############################################################################
## Library Procedure:  vTcl:DoCmdOption

proc ::vTcl:DoCmdOption {target cmd} {
    ## This procedure may be used free of restrictions.
    ##    Exception added by Christian Gavin on 08/08/02.
    ## Other packages and widget toolkits have different licensing requirements.
    ##    Please read their license agreements for details.

    ## menus are considered toplevel windows
    set parent $target
    while {[winfo class $parent] == "Menu"} {
        set parent [winfo parent $parent]
    }

    regsub -all {\%widget} $cmd $target cmd
    regsub -all {\%top} $cmd [winfo toplevel $parent] cmd

    uplevel #0 [list eval $cmd]
}
#############################################################################
## Library Procedure:  vTcl:FireEvent

proc ::vTcl:FireEvent {target event {params {}}} {
    ## This procedure may be used free of restrictions.
    ##    Exception added by Christian Gavin on 08/08/02.
    ## Other packages and widget toolkits have different licensing requirements.
    ##    Please read their license agreements for details.

    ## The window may have disappeared
    if {![winfo exists $target]} return
    ## Process each binding tag, looking for the event
    foreach bindtag [bindtags $target] {
        set tag_events [bind $bindtag]
        set stop_processing 0
        foreach tag_event $tag_events {
            if {$tag_event == $event} {
                set bind_code [bind $bindtag $tag_event]
                foreach rep "\{%W $target\} $params" {
                    regsub -all [lindex $rep 0] $bind_code [lindex $rep 1] bind_code
                }
                set result [catch {uplevel #0 $bind_code} errortext]
                if {$result == 3} {
                    ## break exception, stop processing
                    set stop_processing 1
                } elseif {$result != 0} {
                    bgerror $errortext
                }
                break
            }
        }
        if {$stop_processing} {break}
    }
}
#############################################################################
## Library Procedure:  vTcl:Toplevel:WidgetProc

proc ::vTcl:Toplevel:WidgetProc {w args} {
    ## This procedure may be used free of restrictions.
    ##    Exception added by Christian Gavin on 08/08/02.
    ## Other packages and widget toolkits have different licensing requirements.
    ##    Please read their license agreements for details.

    if {[llength $args] == 0} {
        ## If no arguments, returns the path the alias points to
        return $w
    }
    set command [lindex $args 0]
    set args [lrange $args 1 end]
    switch -- [string tolower $command] {
        "setvar" {
            foreach {varname value} $args {}
            if {$value == ""} {
                return [set ::${w}::${varname}]
            } else {
                return [set ::${w}::${varname} $value]
            }
        }
        "hide" - "show" {
            Window [string tolower $command] $w
        }
        "showmodal" {
            ## modal dialog ends when window is destroyed
            Window show $w; raise $w
            grab $w; tkwait window $w; grab release $w
        }
        "startmodal" {
            ## ends when endmodal called
            Window show $w; raise $w
            set ::${w}::_modal 1
            grab $w; tkwait variable ::${w}::_modal; grab release $w
        }
        "endmodal" {
            ## ends modal dialog started with startmodal, argument is var name
            set ::${w}::_modal 0
            Window hide $w
        }
        default {
            uplevel $w $command $args
        }
    }
}
#############################################################################
## Library Procedure:  vTcl:WidgetProc

proc ::vTcl:WidgetProc {w args} {
    ## This procedure may be used free of restrictions.
    ##    Exception added by Christian Gavin on 08/08/02.
    ## Other packages and widget toolkits have different licensing requirements.
    ##    Please read their license agreements for details.

    if {[llength $args] == 0} {
        ## If no arguments, returns the path the alias points to
        return $w
    }

    set command [lindex $args 0]
    set args [lrange $args 1 end]
    uplevel $w $command $args
}
#############################################################################
## Library Procedure:  vTcl:toplevel

proc ::vTcl:toplevel {args} {
    ## This procedure may be used free of restrictions.
    ##    Exception added by Christian Gavin on 08/08/02.
    ## Other packages and widget toolkits have different licensing requirements.
    ##    Please read their license agreements for details.

    uplevel #0 eval toplevel $args
    set target [lindex $args 0]
    namespace eval ::$target {set _modal 0}
}
}


if {[info exists vTcl(sourcing)]} {

proc vTcl:project:info {} {
    set base .top47
    namespace eval ::widgets::$base {
        set set,origin 1
        set set,size 1
        set runvisible 1
    }
    namespace eval ::widgets::$base.m48 {
        array set save {-tearoff 1 -title 1}
        namespace eval subOptions {
            array set save {-columnbreak 1 -command 1 -compound 1 -label 1 -menu 1 -state 1 -underline 1}
        }
    }
    set site_3_0 $base.m48
    namespace eval ::widgets::$site_3_0.men61 {
        array set save {-tearoff 1}
        namespace eval subOptions {
            array set save {-command 1 -label 1 -menu 1 -underline 1}
        }
    }
    set site_3_0 $base.m48
    namespace eval ::widgets::$site_3_0.men64 {
        array set save {-tearoff 1}
        namespace eval subOptions {
            array set save {-command 1 -label 1 -underline 1}
        }
    }
    set site_3_0 $base.m48
    namespace eval ::widgets::$site_3_0.men65 {
        array set save {-tearoff 1}
        namespace eval subOptions {
            array set save {-command 1 -label 1 -underline 1}
        }
    }
    set site_3_0 $base.m48
    namespace eval ::widgets::$site_3_0.men66 {
        array set save {-tearoff 1}
        namespace eval subOptions {
            array set save {-command 1 -label 1 -underline 1}
        }
    }
    set site_3_0 $base.m48
    namespace eval ::widgets::$site_3_0.men67 {
        array set save {-tearoff 1}
        namespace eval subOptions {
            array set save {-command 1 -label 1 -underline 1}
        }
    }
    namespace eval ::widgets::$base.fra51 {
        array set save {-borderwidth 1 -height 1 -relief 1 -width 1}
    }
    set site_3_0 $base.fra51
    namespace eval ::widgets::$site_3_0.but52 {
        array set save {-image 1 -text 1}
    }
    namespace eval ::widgets::$site_3_0.cpd53 {
        array set save {-height 1 -image 1 -text 1 -width 1}
    }
    set base .top70
    namespace eval ::widgets::$base {
        set set,origin 1
        set set,size 1
        set runvisible 1
    }
    namespace eval ::widgets::$base.fra79 {
        array set save {-borderwidth 1 -height 1 -highlightcolor 1 -relief 1 -width 1}
    }
    set site_3_0 $base.fra79
    namespace eval ::widgets::$site_3_0.cpd82 {
        array set save {-activebackground 1 -activeforeground 1 -foreground 1 -highlightcolor 1 -text 1}
    }
    namespace eval ::widgets::$site_3_0.cpd83 {
        array set save {-activebackground 1 -activeforeground 1 -foreground 1 -highlightcolor 1 -text 1}
    }
    namespace eval ::widgets::$site_3_0.cpd84 {
        array set save {-activebackground 1 -activeforeground 1 -foreground 1 -highlightcolor 1 -text 1}
    }
    namespace eval ::widgets::$site_3_0.lab85 {
        array set save {-activebackground 1 -activeforeground 1 -foreground 1 -highlightcolor 1 -image 1 -text 1}
    }
    namespace eval ::widgets::$base.but86 {
        array set save {-activebackground 1 -activeforeground 1 -foreground 1 -highlightcolor 1 -text 1 -underline 1}
    }
    namespace eval ::widgets_bindings {
        set tagslist _TopLevel
    }
    namespace eval ::vTcl::modules::main {
        set procs {
            init
            main
        }
        set compounds {
        }
        set projectType single
    }
}
}

#################################
# USER DEFINED PROCEDURES
#
#############################################################################
## Procedure:  main

proc ::main {argc argv} {}

#############################################################################
## Initialization Procedure:  init

proc ::init {argc argv} {}

init $argc $argv

#################################
# VTCL GENERATED GUI PROCEDURES
#

proc vTclWindow. {base} {
    if {$base == ""} {
        set base .
    }
    ###################
    # CREATING WIDGETS
    ###################
    wm focusmodel $top passive
    wm geometry $top 1x1+0+0; update
    wm maxsize $top 1009 738
    wm minsize $top 1 1
    wm overrideredirect $top 0
    wm resizable $top 1 1
    wm withdraw $top
    wm title $top "vtcl.tcl"
    bindtags $top "$top Vtcl.tcl all"
    vTcl:FireEvent $top <<Create>>
    wm protocol $top WM_DELETE_WINDOW "vTcl:FireEvent $top <<DeleteWindow>>"

    ###################
    # SETTING GEOMETRY
    ###################

    vTcl:FireEvent $base <<Ready>>
}

proc vTclWindow.top47 {base} {
    if {$base == ""} {
        set base .top47
    }
    if {[winfo exists $base]} {
        wm deiconify $base; return
    }
    set top $base
    ###################
    # CREATING WIDGETS
    ###################
    vTcl:toplevel $top -class Toplevel \
        -menu "$top.m48" -highlightcolor black 
    wm focusmodel $top passive
    wm geometry $top 556x404+163+77; update
    wm maxsize $top 1009 738
    wm minsize $top 1 1
    wm overrideredirect $top 0
    wm resizable $top 1 1
    wm deiconify $top
    wm title $top "Livrus Virtus"
    vTcl:DefineAlias "$top" "frmPrincipal" vTcl:Toplevel:WidgetProc "" 1
    bindtags $top "$top Toplevel all _TopLevel"
    vTcl:FireEvent $top <<Create>>
    wm protocol $top WM_DELETE_WINDOW "vTcl:FireEvent $top <<DeleteWindow>>"

    menu $top.m48 \
        -tearoff 1 -title {Livrus Virtu} 
    vTcl:DefineAlias "$top.m48" "menuPrincipal" vTcl:WidgetProc "" 1
    $top.m48 add cascade \
        -menu "$top.m48.men61" -columnbreak 0 -command {} -compound none \
        -label Cadastros -state normal -underline 0 
    set site_3_0 $top.m48
    menu $site_3_0.men61 \
        -tearoff 0 
    vTcl:DefineAlias "$site_3_0.men61" "menuCadastros" vTcl:WidgetProc "" 1
    $site_3_0.men61 add command \
        -command {# TODO: Your menu handler here} -label Assuntos \
        -underline 0 
    $site_3_0.men61 add command \
        -command {# TODO: Your menu handler here} -label Autores -underline 1 
    $site_3_0.men61 add command \
        -command {# TODO: Your menu handler here} -label Editoras \
        -underline 0 
    $site_3_0.men61 add command \
        -command {# TODO: Your menu handler here} -label Endereços \
        -underline 1 
    $site_3_0.men61 add command \
        -command {# TODO: Your menu handler here} -label Idiomas -underline 0 
    $site_3_0.men61 add command \
        -command {# TODO: Your menu handler here} -label Países -underline 0 
    $site_3_0.men61 add command \
        -command {# TODO: Your menu handler here} -label Profissões \
        -underline 1 
    $site_3_0.men61 add separator \
        
    $site_3_0.men61 add command \
        -command {# TODO: Your menu handler here} -label Clientes \
        -underline 0 
    $site_3_0.men61 add command \
        -command {# TODO: Your menu handler here} -label Livros -underline 0 
    $top.m48 add cascade \
        -menu "$top.m48.men64" -columnbreak 0 -command {} -compound none \
        -label Pesquisas -state normal -underline 0 
    set site_3_0 $top.m48
    menu $site_3_0.men64 \
        -tearoff 0 
    vTcl:DefineAlias "$site_3_0.men64" "menuPesquisas" vTcl:WidgetProc "" 1
    $site_3_0.men64 add command \
        -command {# TODO: Your menu handler here} -label Assuntos \
        -underline 0 
    $site_3_0.men64 add command \
        -command {# TODO: Your menu handler here} -label Autores -underline 1 
    $site_3_0.men64 add command \
        -command {# TODO: Your menu handler here} -label Editoras \
        -underline 0 
    $site_3_0.men64 add command \
        -command {# TODO: Your menu handler here} -label Endereços \
        -underline 1 
    $site_3_0.men64 add command \
        -command {# TODO: Your menu handler here} -label Idiomas -underline 0 
    $site_3_0.men64 add command \
        -command {# TODO: Your menu handler here} -label Países -underline 0 
    $site_3_0.men64 add command \
        -command {# TODO: Your menu handler here} -label Profissões \
        -underline 1 
    $site_3_0.men64 add separator \
        
    $site_3_0.men64 add command \
        -command {# TODO: Your menu handler here} -label Clientes \
        -underline 0 
    $site_3_0.men64 add command \
        -command {# TODO: Your menu handler here} -label Livros -underline 0 
    $top.m48 add cascade \
        -menu "$top.m48.men65" -columnbreak 0 -command {} -compound none \
        -label Vendas -state normal -underline 0 
    set site_3_0 $top.m48
    menu $site_3_0.men65 \
        -tearoff 0 
    vTcl:DefineAlias "$site_3_0.men65" "menuVendas" vTcl:WidgetProc "" 1
    $site_3_0.men65 add command \
        -command {# TODO: Your menu handler here} -label {Vender Livros} \
        -underline 0 
    $site_3_0.men65 add command \
        -command {# TODO: Your menu handler here} -label {Vendas Realizadas} \
        -underline 7 
    $top.m48 add cascade \
        -menu "$top.m48.men66" -columnbreak 0 -command {} -compound none \
        -label Janelas -state normal -underline 0 
    set site_3_0 $top.m48
    menu $site_3_0.men66 \
        -tearoff 0 
    vTcl:DefineAlias "$site_3_0.men66" "menuJanelas" vTcl:WidgetProc "" 1
    $site_3_0.men66 add command \
        -command {# TODO: Your menu handler here} \
        -label {Lado a lado horizontal} -underline 12 
    $site_3_0.men66 add command \
        -command {# TODO: Your menu handler here} \
        -label {Lado a lado vertical} -underline 12 
    $site_3_0.men66 add command \
        -command {# TODO: Your menu handler here} -label {Em cascata} \
        -underline 3 
    $top.m48 add cascade \
        -menu "$top.m48.men67" -columnbreak 0 -command {} -compound none \
        -label Opções -state normal -underline 0 
    set site_3_0 $top.m48
    menu $site_3_0.men67 \
        -tearoff 0 
    vTcl:DefineAlias "$site_3_0.men67" "menuOpcoes" vTcl:WidgetProc "" 1
    $site_3_0.men67 add command \
        -command {# TODO: Your menu handler here} -label {Alterar Senha} \
        -underline 0 
    $site_3_0.men67 add separator \
        
    $site_3_0.men67 add command \
        -command { Window show .top70 } -label Sobre -underline 0 
    $site_3_0.men67 add command \
        -command {# TODO: Your menu handler here} -label Sair -underline 2 
    frame $top.fra51 \
        -borderwidth 1 -relief raised -height 30 -width 555 
    vTcl:DefineAlias "$top.fra51" "ToolBarra" vTcl:WidgetProc "frmPrincipal" 1
    set site_3_0 $top.fra51
    button $site_3_0.but52 \
        \
        -image [vTcl:image:get_image [file join / home hfs livrusvirtus tcl cliente.gif]] \
        -text button 
    vTcl:DefineAlias "$site_3_0.but52" "btnTClientes" vTcl:WidgetProc "frmPrincipal" 1
    button $site_3_0.cpd53 \
        -height 27 \
        -image [vTcl:image:get_image [file join / home hfs livrusvirtus tcl Livro.gif]] \
        -text button -width 27 
    vTcl:DefineAlias "$site_3_0.cpd53" "btnTLivros1" vTcl:WidgetProc "frmPrincipal" 1
    place $site_3_0.but52 \
        -in $site_3_0 -x 5 -y 2 -width 24 -height 24 -anchor nw \
        -bordermode ignore 
    place $site_3_0.cpd53 \
        -in $site_3_0 -x 30 -y 1 -width 24 -height 24 -anchor nw \
        -bordermode inside 
    ###################
    # SETTING GEOMETRY
    ###################
    place $top.fra51 \
        -in $top -x 0 -y 0 -width 555 -height 30 -anchor nw \
        -bordermode ignore 

    vTcl:FireEvent $base <<Ready>>
}

proc vTclWindow.top70 {base} {
    if {$base == ""} {
        set base .top70
    }
    if {[winfo exists $base]} {
        wm deiconify $base; return
    }
    set top $base
    ###################
    # CREATING WIDGETS
    ###################
    vTcl:toplevel $top -class Toplevel \
        -highlightcolor black 
    wm withdraw $top
    wm focusmodel $top passive
    wm geometry $top 354x230+319+100; update
    wm maxsize $top 1009 738
    wm minsize $top 1 1
    wm overrideredirect $top 0
    wm resizable $top 1 1
    wm title $top "Sobre o Sistema"
    vTcl:DefineAlias "$top" "frmSobre" vTcl:Toplevel:WidgetProc "" 1
    bindtags $top "$top Toplevel all _TopLevel"
    vTcl:FireEvent $top <<Create>>
    wm protocol $top WM_DELETE_WINDOW "vTcl:FireEvent $top <<DeleteWindow>>"

    frame $top.fra79 \
        -borderwidth 2 -relief groove -height 175 -highlightcolor black \
        -width 335 
    vTcl:DefineAlias "$top.fra79" "Frame1" vTcl:WidgetProc "frmSobre" 1
    set site_3_0 $top.fra79
    label $site_3_0.cpd82 \
        -activebackground #f9f9f9 -activeforeground black -foreground black \
        -highlightcolor black -text {Versão 1.0.0} 
    vTcl:DefineAlias "$site_3_0.cpd82" "labVersao" vTcl:WidgetProc "frmSobre" 1
    label $site_3_0.cpd83 \
        -activebackground #f9f9f9 -activeforeground black -foreground black \
        -highlightcolor black \
        -text {Todos os direitos reservados para: Henrique F. Souza} 
    vTcl:DefineAlias "$site_3_0.cpd83" "labDireitos" vTcl:WidgetProc "frmSobre" 1
    label $site_3_0.cpd84 \
        -activebackground #f9f9f9 -activeforeground black -foreground black \
        -highlightcolor black -text {Versão programada na liguagem Tk/Tcl} 
    vTcl:DefineAlias "$site_3_0.cpd84" "labLinguagem" vTcl:WidgetProc "frmSobre" 1
    label $site_3_0.lab85 \
        -activebackground #f9f9f9 -activeforeground black -foreground black \
        -highlightcolor black \
        -image [vTcl:image:get_image [file join / home hfs livrusvirtus tcl LivrusVirtus.gif]] \
        -text label 
    vTcl:DefineAlias "$site_3_0.lab85" "Label4" vTcl:WidgetProc "frmSobre" 1
    place $site_3_0.cpd82 \
        -in $site_3_0 -x 245 -y 95 -anchor nw -bordermode inside 
    place $site_3_0.cpd83 \
        -in $site_3_0 -x 5 -y 120 -anchor nw -bordermode inside 
    place $site_3_0.cpd84 \
        -in $site_3_0 -x 40 -y 145 -anchor nw -bordermode inside 
    place $site_3_0.lab85 \
        -in $site_3_0 -x 35 -y 10 -anchor nw -bordermode ignore 
    button $top.but86 \
        -activebackground #f9f9f9 -activeforeground black -foreground black \
        -highlightcolor black -text Ok -underline 0 
    vTcl:DefineAlias "$top.but86" "btnOk" vTcl:WidgetProc "frmSobre" 1
    ###################
    # SETTING GEOMETRY
    ###################
    place $top.fra79 \
        -in $top -x 10 -y 10 -width 335 -height 175 -anchor nw \
        -bordermode ignore 
    place $top.but86 \
        -in $top -x 145 -y 195 -width 82 -height 26 -anchor nw \
        -bordermode ignore 

    vTcl:FireEvent $base <<Ready>>
}

#############################################################################
## Binding tag:  _TopLevel

bind "_TopLevel" <<Create>> {
    if {![info exists _topcount]} {set _topcount 0}; incr _topcount
}
bind "_TopLevel" <<DeleteWindow>> {
    if {[set ::%W::_modal]} {
                vTcl:Toplevel:WidgetProc %W endmodal
            } else {
                destroy %W; if {$_topcount == 0} {exit}
            }
}
bind "_TopLevel" <Destroy> {
    if {[winfo toplevel %W] == "%W"} {incr _topcount -1}
}

Window show .
Window show .top47
Window show .top70

main $argc $argv
