#include "Conditions.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QTextBrowser>

ConditionsWindow::ConditionsWindow(QWidget *parent)
    : QWidget(parent) {
    setWindowTitle("Conditions");

    auto *layout = new QVBoxLayout(this);

    auto *scrollArea = new QScrollArea(this);
    auto *textBrowser = new QTextBrowser(this);

    QString htmlContent = R"(
        <h2>Conditions</h2>
        <p><b>Blinded:</b> A blinded creature can't see and automatically fails any ability check that requires sight. Attack rolls against the creature have advantage, and the creature's attack rolls have disadvantage.</p>
        <p><b>Charmed:</b> A charmed creature can't attack the charmer or target the charmer with harmful abilities or magical effects. The charmer has advantage on any ability check to interact socially with the creature.</p>
        <p><b>Deafened:</b> A deafened creature can't hear and automatically fails any ability check that requires hearing.</p>
        <p><b>Frightened:</b> A frightened creature has disadvantage on ability checks and attack rolls while the source of its fear is within line of sight. The creature can't willingly move closer to the source of is fear</p>
        <p><b>Grappled:</b> A grappled creature's speed becomes 0, and it can't benefit from any bonus to its speed.</p>
        <p><b>Incapacitated:</b> An incapacitated creature can't take actions or reactions.</p>
        <p><b>Invisible:</b> An invisible creature is impossible to see without the aid of magic or a special sense. For the purpose of hiding, the creature is heavily obscured. The creature's location can be detected by any noise it makes or any tracks it leaves. Attack rolls against the creature have disadvantage, and the creature's attack rolls have advantage.</p>
        <p><b>Paralyzed:</b> A paralyzed creature is incapacitated and can't move or speak.The creature automatically fails Str and Dex saving throws. Attack rolls against this creature have advantage. Any attack that hits within 5ft. is a critical hit.</p>
        <p><b>Petrified:</b> A petrified creature is transformed, along with any nonmagical object it is wearing or carrying, into a solid inanimate substance. Its weight increases by a factor of ten, and it ceases aging. The creature is incapacitated, has resistance to all damage, is immune to poison and disease, but a poison or disease already in its system is suspended.</p>
        <p><b>Poisoned:</b> A poisoned creature has disadvantage on attack rolls and ability checks.</p>
        <p><b>Prone:</b> A prone creature's only movement option is to crawl, unless it stands up and thereby ends the condition. The creature has disadvantage on attack rolls. An attack roll against the creature has advantage within 5ft., otherwise it has disadvantage.</p>
        <p><b>Restrained:</b> A restrained creature's speed becomes 0, and it can't benefit from any bonus to its speed. Attack rolls against the creature have advantage, and the creature's attack rolls have disadvantage. The creature has disadvantage on Dex saving throws.</p>
        <p><b>Stunned:</b> A stunned creature is incapacitated, can't move, and can speak only falteringly. The creature automatically fails Str and Dex saving throws. Attack rolls against the creature have advantage.</p>
        <p><b>Unconscious:</b> An unconscious creature is incapacitated, can't move or speak, and is unaware of its surroundings. The creature drops whatever it's holding and falls prone. The creature automatically fails Str and Dex saving throws. Attack rolls against the creature have advantage. Any attack that hits within 5ft. is a critical hit.</p>
    )";

    textBrowser->setHtml(htmlContent);
    textBrowser->setReadOnly(true);

    scrollArea->setWidget(textBrowser);
    scrollArea->setWidgetResizable(true);

    layout->addWidget(scrollArea);
    setLayout(layout);
    resize(500, 600);
}
