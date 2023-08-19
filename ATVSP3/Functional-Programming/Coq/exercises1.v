Variables A B C : Prop.

Theorem first_theorem : (A -> B) -> A -> B.
Proof.
    intros Ha.
    assumption.
Qed.


Lemma ex1 : A -> B -> A.
Proof.
    intros H1.
    intros H2.
    assumption.
Qed.

Lemma ex2 : (A -> B) -> (B -> C) -> A -> C.
Proof.
    intros H1;intros H2;intros H3.
    apply H2;apply H1.
    assumption.
Qed.

Lemma ex3 : (A /\ B) /\ C -> A /\ (B /\ C).
Proof.
    intros H1.
    destruct H1 as [HA HB].
    destruct HA as [Ha Hb].
    split.
    -
    assumption.
    -
    split.
    +
    assumption.
    +
    assumption.
Qed.


Lemma ex4 : ((A /\ B) -> C) -> (A -> B -> C).
Proof.
    intros H1;intros H2;intros H3.
    apply H1.
    split.
    auto.
    auto.
Qed.

Lemma ex5 : (A -> B -> C) -> ((A /\ B) -> C).
Proof.
    intros H1;intros H2.
    destruct H2.
    apply H1.
    assumption.
    assumption.
Qed.

Lemma ex6 : ((A -> B) /\ (A -> C)) -> A -> (B /\ C).
Proof.
    intros H1;intros H2.
    destruct H1 as [HA HB].
    split.
    +
    apply HA.
    assumption.
    +
    apply HB.
    assumption.
Qed.

Lemma and_comm_iff : (A /\ B) <-> (B /\ A).
Proof.
    unfold iff.
    split.
    +
    intros H1.
    destruct H1 as [HA HB].
    split.
    assumption.
    assumption.
    +
    intros H2.
    destruct H2 as [HC HD].
    split.
    assumption.
    assumption.
Qed.

Lemma modus_tollens : ((A -> B) /\ ~ B) -> ~ A.
Proof.
    intros H1.
    destruct H1 as [HA HB].
    unfold not.
    intros H2.
    unfold not in HB.
    apply HB.
    apply HA.
    assumption.
Qed.

Lemma contra : A -> ~ A -> B.
Proof.
    intros H1.
    intros H2.
    contradiction.
Qed.

Lemma ex7 : ((A \/ B) /\ ~ A) -> B.
Proof.
    intros H1.
    destruct H1 as [HA HB].
    destruct HA as [Hc | Hd].
    +
    contradiction.
    +
    assumption.
Qed.

Lemma ex8 : (A \/ (B /\ C)) -> (A \/ B) /\ (A \/ C).
Proof.
    intros H1.
    destruct H1 as [HA | HB].
    +
    split.
    -
    left.
    assumption.
    -
    left.
    assumption.
    +
    destruct HB as [Hb Hc].
    split.
    *
    right.
    assumption.
    *
    right.
    assumption.
Qed.



Hypothesis U : Set.
  Hypothesis u : U.
  Hypothesis P : U -> Prop.
  Hypothesis Q : U -> Prop.
  Hypothesis R : U -> Prop.

Lemma ex9 : forall x : U, P x -> exists y : U, P y.
Proof.
    intros x.
    intros H1.
    exists x.
    assumption.
Qed.

Lemma ex10 : (forall x : U, P x -> ~ Q x) -> ~ exists y : U, P y /\ Q y.
Proof.
    intros H1.
    intros H2.
    destruct H2 as [x HB].
    destruct HB as [HC HD].
    apply (H1 x).
    assumption.
    assumption.
Qed.

Lemma ex11 : (forall x : U, P x -> Q x) -> (forall x : U, ~ Q x) -> (forall x : U, ~ P x).
Proof.
    intros H1.
    intros H2.
    intros x.
    intros H3.
    unfold not in H2.
    apply (H2 x).
    apply (H1 x).
    assumption.
Qed.




    


    

    
    
    















    








