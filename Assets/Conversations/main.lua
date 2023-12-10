-- main script component

require("conversation.core")

local ConversationScriptComponent = ScriptDialogueComponent:new(nil)

function ConversationScriptComponent:InitConversationScript()
	-- BOP_GENERATED_INSTRUCTIONS_BEGIN: in_branch1, in_branch2, in_branch3, in_branch4
-- Begin node2_actor_dialogue settings
    self:AddCondition('node2_actor_dialogue', "{268F3CF8-9840-5232-B5D1-C55EDBDC4EBD}");
-- End node2_actor_dialogue settings
-- Begin node3_actor_dialogue settings
    self:AddCondition('node3_actor_dialogue', "{07B6C335-053A-5EF2-A3D2-E3EB568C72BF}");
-- End node3_actor_dialogue settings
	-- BOP_GENERATED_INSTRUCTIONS_END
end

function ConversationScriptComponent:OnActivate()
	self:ActivateConversationScript() -- Required since defining OnActivate in the metaclass doesn't seem to work.
end

function ConversationScriptComponent:OnDeactivate()
	self:DeactivateConversationScript() -- Required since defining OnActivate in the metaclass doesn't seem to work.
end

return ConversationScriptComponent
