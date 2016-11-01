#include "ScreenCampaignSelect.h"
#include "Renderer.h"
#include "Campaign.h"
#include "ScreenCharacterSelect.h"


ScreenCampaignSelect::ScreenCampaignSelect(Game* game) : Screen(game)
{
	Button* defaultCampaignButton = new Button("Default Campaign",&Renderer::FONT_ROBOTO, 100,300,0,0);
	defaultCampaignButton->setFontColor(255, 255, 255, 255);
	defaultCampaignButton->adjustButtonDimensions();
	defaultCampaignButton->addOnClick_callback([this](Component* comp, int x, int y)
	{
		Campaign* campaign = new Campaign("Default");
		Renderer::addVoidScreen(this->game->getGuiManager()->setScreen(new ScreenCharacterSelect(this->game, campaign)));
	});

	addComponent(defaultCampaignButton);
}

void ScreenCampaignSelect::render()
{
	Screen::render();
}