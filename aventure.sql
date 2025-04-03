CREATE TABLE IF NOT EXISTS lieux (
nom TEXT,
descri TEXT,
id INT,
access BOOL
);
CREATE TABLE IF NOT EXISTS objets (
nom TEXT, 
descri TEXT,
id INT,
id_lieu INT
);
CREATE TABLE IF NOT EXISTS joueurs (
nom TEXT,
id INT,
HP INT,
STR INT,
position_id INT
);
CREATE TABLE IF NOT EXISTS NPCs (
nom TEXT,
id INT,
descri TEXT,
id_lieu INT,
dialogue TEXT
);
CREATE TABLE IF NOT EXISTS ennemis (
nom TEXT,
id INT,
HP INT,
STR INT,
id_lieu INT
);
CREATE TABLE IF NOT EXISTS inventaire (
id INT,
id_joueur INT,
id_objet INT
);
CREATE TABLE IF NOT EXISTS quetes (
id INT,
descri TEXT,
est_complete INT,
id_joueur,
id_NPC
);
CREATE TABLE IF NOT EXISTS quetes_NPCs (
id INT,
id_NPC INT,
id_quete INT
);

INSERT INTO lieux (nom, descri, id, access)
VALUES
('Haunted Mines', 'Abandonned dwarvish mines, believed to be haunted by their ghosts.', 1, 1),
('Dark Forest', 'ksdnfgkamk', 2, 0),
('Troll Village', 'nsfngkrnnms', 3, 0);

INSERT INTO objets (nom, descri, id, id_lieu)
VALUES
('Pickaxe', 'steel mining equipment.', 1, 1),
('Torch', 'a tree branch.', 2, 2),
('Health Potion', 'a bottle of red healing liquid.', 3, 3),
('Staff', 'a magical weapon.', 4, 2),
('Sword', 'a rusted sword.', 5, 3);

--ADD PLAYER

INSERT INTO ennemis (nom, id, HP, STR, id_lieu)
VALUES
('Troll', 1, 20, 5, 3),
('Goblin', 2, 10, 2, 3),
('Gnoll', 3, 15, 5, 3),
('Dwarf Ghost', 4, 15, 5, 1),
('Dark Elf', 5, 20, 8, 2);

