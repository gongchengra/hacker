package slotMachineGUI;

import java.awt.*;
import javax.swing.*;
import javax.swing.LayoutStyle.ComponentPlacement;
import java.text.DecimalFormat;
import java.util.Random;
import java.util.ArrayList;
import javax.swing.border.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SlotMachineGUI {

    private JButton btnCash, btnSpin;
    private JCheckBox cbAlwaysWin, cbSuperJackpot, cbTrollface;
    private JFrame frmFrame;
    private JLabel lblCredits, lblLost, lblMatchThree, lblMatchTwo, lblMoney, lblReel1, lblReel2, lblReel3, lblStatus, lblWon;
    private JPanel pnlReels, pnlReel1, pnlReel2, pnlReel3;
    private JProgressBar prgbarCheatUnlocker;
    private JSeparator sepCheats, sepStats, sepStats2, sepStatus;
    private JToggleButton tgglSound;
    private int credits = 100, boughtCredits = 100, bet = 15, matchThree, matchTwo, win, lost;
    private double payout = 25.0, creditBuyout = 10.0, funds;
    private int reel1 = 7, reel2 = 7, reel3 = 7; // starting values of the reels.
    private ArrayList<ImageIcon> images = new ArrayList<ImageIcon>();
    private DecimalFormat df = new DecimalFormat("0.00");

    public SlotMachineGUI(int credits, int boughtCredits, int bet, double payout, double creditBuyout, int reel1, int reel2, int reel3) {
        this.credits=credits;
        this.boughtCredits=boughtCredits;
        this.bet=bet;
        this.payout=payout;
        this.creditBuyout=creditBuyout;
        this.reel1=reel1;
        this.reel2=reel2;
        this.reel3=reel3;
        createForm();
        loadImages();
        addFields();
        addButtons();
        layoutFrame();
        layoutReels();
        layoutOther();
    }

    public SlotMachineGUI() {
        createForm();
        loadImages();
        addFields();
        addButtons();
        layoutFrame();
        layoutReels();
        layoutOther();
    }

    /** Creates the JFrame and Panels. */
    private void createForm() {

        frmFrame = new JFrame();
        frmFrame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        frmFrame.setTitle("Warner Slots");
        frmFrame.setResizable(false);
        frmFrame.setVisible(true);

        pnlReels = new JPanel();
        pnlReels.setBorder(BorderFactory.createEtchedBorder());

        pnlReel1 = new JPanel();
        pnlReel1.setBackground(new Color(255, 215, 0));
        pnlReel1.setBorder(new SoftBevelBorder(BevelBorder.LOWERED));
        pnlReel2 = new JPanel();
        pnlReel2.setBackground(new Color(255, 216, 0));
        pnlReel2.setBorder(new SoftBevelBorder(BevelBorder.LOWERED));
        pnlReel3 = new JPanel();
        pnlReel3.setBackground(new java.awt.Color(255, 215, 0));
        pnlReel3.setBorder(new SoftBevelBorder(BevelBorder.LOWERED));

    }

    /** Adds labels to the form. */
    private void addFields() {

        lblReel1 = new JLabel();
        lblReel2 = new JLabel();
        lblReel3 = new JLabel();

        sepStats = new JSeparator();
        lblMatchTwo = new JLabel();
        lblMatchTwo.setText("Matched Two: ");
        lblMatchThree = new JLabel();
        lblMatchThree.setText("Matched Three: ");
        lblWon = new JLabel();
        lblWon.setText("Won: ");

        sepStats2 = new JSeparator();
        sepStats2.setOrientation(SwingConstants.VERTICAL);
        lblCredits = new JLabel();
        lblCredits.setText("Credits: "+credits);
        lblMoney = new JLabel();
        lblMoney.setText("Money: £"+df.format(funds));
        lblLost = new JLabel();
        lblLost.setText("Lost: ");

        sepStatus = new JSeparator();
        lblStatus = new JLabel();
        lblStatus.setBackground(new Color(255, 255, 255));
        lblStatus.setFont(new Font("Arial", 1, 14));
        lblStatus.setHorizontalAlignment(SwingConstants.CENTER);
        lblStatus.setText("Welcome to WARNER SLOTS!!! ©2012");

        sepCheats = new JSeparator();
        prgbarCheatUnlocker = new JProgressBar();
        prgbarCheatUnlocker.setToolTipText("Fill the bar to unlock the cheat menu.");

        lblReel1.setIcon(images.get(reel1));
        lblReel2.setIcon(images.get(reel2));
        lblReel3.setIcon(images.get(reel3));

    }

    /** Adds buttons to the form. */
    private void addButtons() {

        btnSpin = new JButton();
        btnSpin.setBackground(new Color(50, 255, 50));
        btnSpin.setText("Spin");
        btnSpin.setToolTipText("Click to spin the reels!");
        btnSpin.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
        btnSpin.setInheritsPopupMenu(true);
        btnSpin.setMaximumSize(new Dimension(200, 50));
        btnSpin.setMinimumSize(new Dimension(200, 50));
        btnSpin.addActionListener(new SpinHandler());

        btnCash = new JButton();
        btnCash.setBackground(new Color(255, 0, 0));
        btnCash.setText("Buy Credits");
        btnCash.setToolTipText("£"+df.format(bet)+" converts to "+boughtCredits+" credits.");
        btnCash.setHorizontalTextPosition(SwingConstants.CENTER);
        btnCash.addActionListener(new BuyCreditsHandler());

        tgglSound = new JToggleButton();
        tgglSound.setSelected(false);
        tgglSound.setText("Sound ON");
        tgglSound.addActionListener(new SoundHandler());

        cbAlwaysWin = new JCheckBox();
        cbAlwaysWin.setText("Always Win Mode");
        cbAlwaysWin.setEnabled(false);
        cbAlwaysWin.addActionListener(new AlwaysWinHandler());

        cbTrollface = new JCheckBox();
        cbTrollface.setText("Trollface");
        cbTrollface.setEnabled(false);
        cbTrollface.addActionListener(new TrollfaceHandler());

        cbSuperJackpot = new JCheckBox();
        cbSuperJackpot.setText("Super Jackpot");
        cbSuperJackpot.setEnabled(false);
        cbSuperJackpot.addActionListener(new SuperPrizeHandler());

    }

    /** Lays out the frame. */
    private void layoutFrame() {

        GroupLayout frameLayout = new GroupLayout(frmFrame.getContentPane());
        frmFrame.getContentPane().setLayout(frameLayout);
        frameLayout.setHorizontalGroup(
                frameLayout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGap(0, 400, Short.MAX_VALUE)
                );
        frameLayout.setVerticalGroup(
                frameLayout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGap(0, 300, Short.MAX_VALUE)
                );
    }

    /** Lays out the panels and reels. */
    private void layoutReels() {

        GroupLayout pnlReelsLayout = new GroupLayout(pnlReels);
        pnlReels.setLayout(pnlReelsLayout);
        pnlReelsLayout.setHorizontalGroup(
                pnlReelsLayout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGroup(pnlReelsLayout.createSequentialGroup()
                    .addContainerGap()
                    .addComponent(pnlReel1, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
                    .addGap(18, 18, 18)
                    .addComponent(pnlReel2, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
                    .addGap(18, 18, 18)
                    .addComponent(pnlReel3, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
                    .addContainerGap(GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                );
        pnlReelsLayout.setVerticalGroup(
                pnlReelsLayout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGroup(pnlReelsLayout.createSequentialGroup()
                    .addContainerGap()
                    .addGroup(pnlReelsLayout.createParallelGroup(GroupLayout.Alignment.TRAILING, false)
                        .addComponent(pnlReel2, GroupLayout.Alignment.LEADING, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(pnlReel1, GroupLayout.Alignment.LEADING, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(pnlReel3, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addContainerGap(GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                );

        GroupLayout pnlReel1Layout = new GroupLayout(pnlReel1);
        pnlReel1.setLayout(pnlReel1Layout);
        pnlReel1Layout.setHorizontalGroup(
                pnlReel1Layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGroup(pnlReel1Layout.createSequentialGroup()
                    .addContainerGap()
                    .addComponent(lblReel1)
                    .addContainerGap(GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                );
        pnlReel1Layout.setVerticalGroup(
                pnlReel1Layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGroup(pnlReel1Layout.createSequentialGroup()
                    .addContainerGap()
                    .addComponent(lblReel1)
                    .addContainerGap(GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                );

        GroupLayout pnlReel2Layout = new GroupLayout(pnlReel2);
        pnlReel2.setLayout(pnlReel2Layout);
        pnlReel2Layout.setHorizontalGroup(
                pnlReel2Layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGroup(pnlReel2Layout.createSequentialGroup()
                    .addContainerGap()
                    .addComponent(lblReel2)
                    .addContainerGap(GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                );
        pnlReel2Layout.setVerticalGroup(
                pnlReel2Layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGroup(pnlReel2Layout.createSequentialGroup()
                    .addContainerGap()
                    .addComponent(lblReel2)
                    .addContainerGap(GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                );

        GroupLayout pnlReel3Layout = new GroupLayout(pnlReel3);
        pnlReel3.setLayout(pnlReel3Layout);
        pnlReel3Layout.setHorizontalGroup(
                pnlReel3Layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGroup(pnlReel3Layout.createSequentialGroup()
                    .addContainerGap()
                    .addComponent(lblReel3)
                    .addContainerGap(GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                );
        pnlReel3Layout.setVerticalGroup(
                pnlReel3Layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGroup(pnlReel3Layout.createSequentialGroup()
                    .addContainerGap()
                    .addComponent(lblReel3)
                    .addContainerGap(GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                );

    }

    /** lays out the remaining labels, check boxes, progress bars, etc. */
    private void layoutOther() {

        GroupLayout layout = new GroupLayout(frmFrame.getContentPane());
        frmFrame.getContentPane().setLayout(layout);

        layout.setHorizontalGroup(
                layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                    .addContainerGap()
                    .addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                        .addGroup(layout.createSequentialGroup()
                            .addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING, false)
                                .addComponent(sepCheats)
                                .addComponent(prgbarCheatUnlocker, GroupLayout.DEFAULT_SIZE, 426, Short.MAX_VALUE))
                            .addGap(0, 0, Short.MAX_VALUE))
                        .addGroup(layout.createSequentialGroup()
                            .addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                                .addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING, false)
                                    .addGroup(layout.createSequentialGroup()
                                        .addComponent(cbAlwaysWin)
                                        .addGap(18, 18, 18)
                                        .addComponent(cbTrollface)
                                        .addGap(18, 18, 18)
                                        .addComponent(cbSuperJackpot)
                                        .addPreferredGap(ComponentPlacement.RELATED, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(tgglSound))
                                    .addComponent(btnSpin, GroupLayout.Alignment.TRAILING, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                    .addComponent(pnlReels, GroupLayout.Alignment.TRAILING, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                    .addComponent(sepStats, GroupLayout.Alignment.TRAILING)
                                    .addComponent(lblStatus, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                    .addGroup(layout.createSequentialGroup()
                                        .addGroup(layout.createParallelGroup(GroupLayout.Alignment.TRAILING, false)
                                            .addComponent(lblMatchTwo, GroupLayout.Alignment.LEADING, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                            .addComponent(lblWon, GroupLayout.Alignment.LEADING, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                            .addComponent(lblMatchThree, GroupLayout.DEFAULT_SIZE, 149, Short.MAX_VALUE))
                                        .addPreferredGap(ComponentPlacement.UNRELATED)
                                        .addComponent(sepStats2, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
                                        .addPreferredGap(ComponentPlacement.UNRELATED)
                                        .addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING, false)
                                            .addComponent(lblLost, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                            .addComponent(lblCredits, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                            .addComponent(lblMoney, GroupLayout.DEFAULT_SIZE, 154, Short.MAX_VALUE))
                                        .addGap(0, 0, Short.MAX_VALUE)))
                                        .addGroup(layout.createParallelGroup(GroupLayout.Alignment.TRAILING)
                                                .addComponent(btnCash)
                                                .addComponent(sepStatus, GroupLayout.PREFERRED_SIZE, 426, GroupLayout.PREFERRED_SIZE)))
                                                .addContainerGap())))
                                                );

        layout.setVerticalGroup(
                layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                    .addContainerGap()
                    .addComponent(pnlReels, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
                    .addPreferredGap(ComponentPlacement.RELATED)
                    .addComponent(btnSpin, GroupLayout.PREFERRED_SIZE, 56, GroupLayout.PREFERRED_SIZE)
                    .addPreferredGap(ComponentPlacement.UNRELATED)
                    .addComponent(sepStats, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
                    .addPreferredGap(ComponentPlacement.UNRELATED)
                    .addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                        .addGroup(layout.createSequentialGroup()
                            .addComponent(lblWon, GroupLayout.PREFERRED_SIZE, 19, GroupLayout.PREFERRED_SIZE)
                            .addPreferredGap(ComponentPlacement.RELATED)
                            .addComponent(lblMatchTwo, GroupLayout.PREFERRED_SIZE, 19, GroupLayout.PREFERRED_SIZE)
                            .addPreferredGap(ComponentPlacement.RELATED)
                            .addComponent(lblMatchThree, GroupLayout.DEFAULT_SIZE, 25, Short.MAX_VALUE))
                        .addComponent(sepStats2)
                        .addGroup(layout.createSequentialGroup()
                            .addComponent(lblLost, GroupLayout.PREFERRED_SIZE, 19, GroupLayout.PREFERRED_SIZE)
                            .addPreferredGap(ComponentPlacement.RELATED)
                            .addComponent(lblCredits, GroupLayout.PREFERRED_SIZE, 19, GroupLayout.PREFERRED_SIZE)
                            .addPreferredGap(ComponentPlacement.RELATED)
                            .addComponent(lblMoney, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addComponent(btnCash, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addPreferredGap(ComponentPlacement.UNRELATED)
                    .addComponent(sepStatus, GroupLayout.PREFERRED_SIZE, 2, GroupLayout.PREFERRED_SIZE)
                    .addPreferredGap(ComponentPlacement.UNRELATED)
                    .addComponent(lblStatus, GroupLayout.PREFERRED_SIZE, 30, GroupLayout.PREFERRED_SIZE)
                    .addPreferredGap(ComponentPlacement.UNRELATED)
                    .addComponent(sepCheats, GroupLayout.PREFERRED_SIZE, 5, GroupLayout.PREFERRED_SIZE)
                    .addPreferredGap(ComponentPlacement.RELATED)
                    .addComponent(prgbarCheatUnlocker, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
                    .addPreferredGap(ComponentPlacement.UNRELATED)
                    .addGroup(layout.createParallelGroup(GroupLayout.Alignment.BASELINE)
                            .addComponent(cbAlwaysWin)
                            .addComponent(cbTrollface)
                            .addComponent(cbSuperJackpot)
                            .addComponent(tgglSound))
                    .addContainerGap())
                    );

        frmFrame.pack();

    }

    /** Performs action when Buy Credits button is clicked. */
    class BuyCreditsHandler implements ActionListener {
        public void actionPerformed(ActionEvent event) {
            buyCredits();
        }
    }

    /** if the player has enough funds credits are added. */
    public void buyCredits() {
        if (funds >= creditBuyout) {
            funds -= creditBuyout;
            lblMoney.setText("Money: £"+df.format(funds));
            credits += boughtCredits;
            lblCredits.setText("Credits: "+credits);
            lblStatus.setText("+"+boughtCredits+" credits purchased! -£"+df.format(creditBuyout));
        } else {
            lblStatus.setText("Insufficient £ to purchase credits!");
        }
        buyCreditsCheck();
    }

    /** if user has enough funds to buy credits changes buttons colour to alert user. */
    public void buyCreditsCheck() {
        if (funds < bet) {
            btnCash.setBackground(new java.awt.Color(255, 0, 0));
        } else {
            btnCash.setBackground(new java.awt.Color(50, 255, 50));
        }
    }

    /** Performs action when Spin button is clicked. */
    class SpinHandler implements ActionListener {
        public void actionPerformed(ActionEvent event) {
            if (funds < creditBuyout && credits < bet) {
                lblStatus.setText("<html><a href='http://www.gambleaware.co.uk/'>www.gambleaware.co.uk</a></html>");
            } else if ((credits - bet) >= 0) {
                pnlReel1.setBackground(new java.awt.Color(255, 215, 0));
                pnlReel2.setBackground(new java.awt.Color(255, 215, 0));
                pnlReel3.setBackground(new java.awt.Color(255, 215, 0));
                genReelNumbers();
                matchCheck();
            } else {
                lblStatus.setText("Bet is "+bet+" credits, purchase more with £!");
            }
            buyCreditsCheck();
        }
    }

    /** Generates the 3 reel numbers. */
    public void genReelNumbers() {
        Random rand = new Random();
        if (cbAlwaysWin.isSelected() == true) { // If the Always win cheat mode is enabled.
            int winType = rand.nextInt(4); // generates number between 0-3 to determine the type of win
            reel1 = rand.nextInt(images.size());
            if (winType == 0) { // winType = 0 - Reels 1, 2 and 3 will all match.
                reel2 = reel1;
                reel3 = reel1;
            } else if (winType == 1) { // winType = 1 - Reels 1 and 2 will match.
                reel2 = reel1;
            } else if (winType == 2) { // winType = 2 - Reels 1 and 3 will match.
                reel3 = reel1;
            } else {    // winType = 3 - Reels 2 and 3 will match.
                if (reel1 >= 0 ) {
                    reel2 = reel1 + 1;
                    reel3 = reel1 + 1;
                } if (reel1 == images.size()-1) {
                    reel2 = reel1 - 1;
                    reel3 = reel1 - 1;
                }
            }
        } else { // If the Always win cheat mode is disabled play a normal game.
            reel1 = rand.nextInt(images.size());
            reel2 = rand.nextInt(images.size());
            reel3 = rand.nextInt(images.size());
        }
        setReelIcon(reel1, reel2, reel3); // Set the reel image
    }

    /** Sets the reels icon based on loaded image in images ArrayList. */
    public void setReelIcon(int ico1, int ico2, int ico3) {
        lblReel1.setIcon(images.get(ico1)); // icon = the ArrayList index = random reel number
        lblReel2.setIcon(images.get(ico2));
        lblReel3.setIcon(images.get(ico3));
    }

    /** Checks for number matches and adjusts score depending on result. */
    public void matchCheck() {
        if (reel1 == reel2 && reel2 == reel3) {
            lblStatus.setText("You matched THREE symbols ("+images.get(reel1).getDescription()+")! +£"+df.format(getPrize(payout))+"!");
            lblMatchThree.setText("Matched Three: "+matchThree());
            pnlReel1.setBackground(new java.awt.Color(255, 0, 0)); // Highlights matched icons.
            pnlReel2.setBackground(new java.awt.Color(255, 0, 0));
            pnlReel3.setBackground(new java.awt.Color(255, 0, 0));
        } else if (reel1 == reel2 || reel1 == reel3) {
            lblStatus.setText("You matched TWO symbols ("+images.get(reel1).getDescription()+")! +£"+df.format(getPrize(payout))+"!");
            lblMatchTwo.setText("Matched Two: "+matchTwo());
            if (reel1 == reel2) {
                pnlReel1.setBackground(new java.awt.Color(255, 0, 0)); // Highlights matched icons.
                pnlReel2.setBackground(new java.awt.Color(255, 0, 0));
            } else if (reel1 == reel3){
                pnlReel1.setBackground(new java.awt.Color(255, 0, 0)); // Highlights matched icons.
                pnlReel3.setBackground(new java.awt.Color(255, 0, 0));
            }
        } else if (reel2 == reel3) {
            lblStatus.setText("You matched TWO symbols ("+images.get(reel2).getDescription()+")! +£"+df.format(getPrize(payout))+"!");
            lblMatchTwo.setText("Matched Two: "+matchTwo());
            pnlReel2.setBackground(new java.awt.Color(255, 0, 0)); // Highlights matched icons.
            pnlReel3.setBackground(new java.awt.Color(255, 0, 0));
        } else {
            lblStatus.setText("Sorry, you didn't match any symbols. -"+bet+" credits!");
            lblLost.setText("Lost: "+lose());
        }
        lblCredits.setText("Credits: "+(credits -= bet)); // deduct bet amount from available credits.
        lblMoney.setText("Money: £"+df.format((funds += getPrize(payout)))); // If there is a win add amount to cash pot.
        lblWon.setText("Wins: "+win()); // increment win amount.
    }

    /** sets progress bar equal to the current win count. if bar is full it unlocks cheat menu */
    public void prgBarCheck() {
        if (prgbarCheatUnlocker.getValue() <= 99) {
            prgbarCheatUnlocker.setValue(win);
        } else if (prgbarCheatUnlocker.getValue() == 100) { // after 100 wins unlock the cheats.
            prgbarCheatUnlocker.setValue(100);
            lblStatus.setText("100 wins! Congratulations you've unlocked the cheat menu!");
            cbTrollface.setEnabled(true);
            cbSuperJackpot.setEnabled(true);
            cbAlwaysWin.setEnabled(true);
        }
    }

    /** calculates prize to be awarded for win based on number of matches and cheats. */
    public double getPrize(double prize) {
        if (reel1 == reel2 && reel2 == reel3) {
            if (cbSuperJackpot.isSelected() == true) {
                prize *= 100; // if cheating and all are matched return the full pay out x100.
            } else {
                prize = payout; // if all are matched return the full pay out.
            }
        } else if (reel1 == reel2 || reel1 == reel3 || reel2 == reel3) {
            if (cbSuperJackpot.isSelected() == true) {
                prize *= 50; // if cheating and two are matched return the pay out x50.
            } else {
                prize = payout / 5; // if two are matched return 1/5th of the pay out.
            }
        } else {
            prize = 0; // If no win return no prize.
        }
        return prize;
    }

    /** Performs action when Super Jack pot check box is clicked. */
    class SuperPrizeHandler implements ActionListener{
        public void actionPerformed(ActionEvent e) {
            if (cbSuperJackpot.isSelected() == true) {
                lblStatus.setText("Super Prize mode ENABLED! The £ won is now x100!");
            }
            if (cbSuperJackpot.isSelected() == false) {
                lblStatus.setText("Super Prize mode DISABLED! :'(");
            }
        }
    }

    /** Performs action when Troll face check box is clicked. */
    class AlwaysWinHandler implements ActionListener{
        public void actionPerformed(ActionEvent e) {
            if (cbAlwaysWin.isSelected() == true) {
                lblStatus.setText("Always Win mode ENABLED! 7-7-7's here we come!");
            }
            if (cbAlwaysWin.isSelected() == false) {
                lblStatus.setText("Always Win mode DISABLED! :'(");
            }
        }
    }

    /** Performs action when Troll face check box is clicked. */
    class TrollfaceHandler implements ActionListener{
        public void actionPerformed(ActionEvent e) {
            if (cbTrollface.isSelected() == true && images.get(images.size()-1) != createImageIcon("images/Trollface.png", "Trollface")) {
                images.add(createImageIcon("images/Trollface.png", "Trollface")); // adds a bonus image to the images ArrayList.
                lblStatus.setText("Trollface mode ENABLED! Trolololololol!");
            }
            if (cbTrollface.isSelected() == false && images.get(images.size()-1) != createImageIcon("images/Trollface.png", "Trollface")) {
                images.remove(images.size()-1); // removes the bonus image (or last one added to the ArrayList) from the images ArrayList.
                lblStatus.setText("Trollface mode DISABLED! :'(");
            }
        }
    }

    /** Performs action when sound toggle button is clicked.
     * NOT IMPLEMENTED
     */
    class SoundHandler implements ActionListener{
        public void actionPerformed(ActionEvent e) {
            if (tgglSound.isSelected() == false) {
                tgglSound.setText("Sound ON");
                lblStatus.setText("Sound effects have been ENABLED!");
                // allowed to play sounds
            } else {
                tgglSound.setText("Sound OFF");
                lblStatus.setText("Sound effects have been DISABLED!");
                // disable sounds
            }
        }
    }

    /** Loads ImageIcons into the images ArrayList.
     *    The difficulty is determined by the number of images present in the ArrayList:
     *    •    Add images here to make game more difficult.
     *    •    Remove images here to make game easier.
     */
    public void loadImages() {
        images.add(createImageIcon("images/Banana.png", "Banana"));
        images.add(createImageIcon("images/Bar.png", "Bar"));
        images.add(createImageIcon("images/Bell.png", "Bell"));
        images.add(createImageIcon("images/Cherry.png", "Cherry"));
        images.add(createImageIcon("images/Clover.png", "Clover"));
        images.add(createImageIcon("images/Diamond.png", "Diamond"));
        images.add(createImageIcon("images/Plum.png", "Plum"));
        images.add(createImageIcon("images/Seven.png", "Seven"));
        images.add(createImageIcon("images/Watermelon.png", "Watermelon"));
    }

    /** Create a new ImageIcon, unless the URL is not found. */
    public ImageIcon createImageIcon(String path, String description) {
        java.net.URL imgURL = getClass().getResource(path);
        if (imgURL != null) {
            return new ImageIcon(imgURL, description);
        } else {
            System.err.println("Couldn't find file: " + path);
            return null;
        }
    }

    /** Increments matchThree by 1 and returns value. */
    public int matchThree() {
        matchThree++;
        return matchThree;
    }

    /** Increments matchTwo by 1 and returns value. */
    public int matchTwo() {
        matchTwo++;
        return matchTwo;
    }

    /** Increments lost by 1 and returns value. */
    public int lose() {
        lost++;
        return lost;
    }

    /** Increments win by 1, increases progress bar and returns value. */
    public int win() {
        win = matchThree + matchTwo;
        prgBarCheck(); // Increments the progress bar to unlock cheat menu.
        return win;
    }

    public static void main(String args[]) {

        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(SlotMachineGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(SlotMachineGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(SlotMachineGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(SlotMachineGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }

        java.awt.EventQueue.invokeLater(new Runnable() {

            public void run() {
                new SlotMachineGUI();
            }
        });

    }

}
