module TextEditor

mutable struct Editor
    text::String
    undo_stack::Vector{String}
    redo_stack::Vector{String}
end

function Editor()
    return Editor("", String[], String[])
end

function type_text(editor::Editor, new_text::String)
    push!(editor.undo_stack, editor.text)
    editor.text *= new_text
    empty!(editor.redo_stack)  # Clear redo stack
    println("Đã gõ: $new_text")
    display(editor)
end

function undo(editor::Editor)
    if !isempty(editor.undo_stack)
        push!(editor.redo_stack, editor.text)
        editor.text = pop!(editor.undo_stack)
        println("Đã hoàn tác hành động.")
        display(editor)
    else
        println("Không có hành động nào để hoàn tác.")
    end
end

function redo(editor::Editor)
    if !isempty(editor.redo_stack)
        push!(editor.undo_stack, editor.text)
        editor.text = pop!(editor.redo_stack)
        println("Đã làm lại hành động.")
        display(editor)
    else
        println("Không có hành động nào để làm lại.")
    end
end

function display(editor::Editor)
    println("Văn bản hiện tại: '$(editor.text)'\n")
end

end  # module TextEditor

# Minh họa sử dụng
using .TextEditor

# Tạo đối tượng editor và thực hiện các hành động
editor = TextEditor.Editor()
TextEditor.type_text(editor, "Hello")
TextEditor.type_text(editor, " World")
TextEditor.undo(editor)
TextEditor.undo(editor)
TextEditor.redo(editor)
